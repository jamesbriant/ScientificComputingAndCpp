#include <cmath>
#include <iostream>
#include "linear_algebra.hpp"
#include "general.hpp"

void ApplyBiGCstab(int n, double* pxEstimate, double** pA, double* px0, 
                        double* pb, double tol, int maxIter)
// Returns solution to Ax=b where A is a known tridiagonal matrix and b is known
// Uses the biconjugate gradient stabilised method.
{
    // Set up x, r and rhat
    double* p_x;
    double* p_rhat;
    double* p_r;
    p_x = new double[n];
    p_rhat = new double[n];
    p_r = new double[n];
    CopyVector(n, px0, p_x);
    CalculateR0(n, p_r, pb, pA, px0);
    CopyVector(n, p_r, p_rhat);

    // Set up p and nu
    double* p_p;
    double* p_nu;
    p_p = new double[n];
    p_nu = new double[n];
    PopulateVector0(n, p_p);
    PopulateVector0(n, p_nu);

    // Set up rho, alpha and omega
    double rho0 = 1;
    double alpha = 1;
    double omega = 1;

    // set up variables that do not require instantiating
    double beta;
    double rho1;
    double norm;
    double* p_h;
    double* p_s;
    double* p_t;
    p_h = new double[n];
    p_s = new double[n];
    p_t = new double[n];

    int counter = 1;
    
    // Algorithm implementation
    do
    {
        // Steps 1-6
        rho1 = InnerProduct(n, p_rhat, p_r);
        beta = (rho1*alpha)/(rho0*omega);
        CalculateP(n, p_p, p_r, p_nu, beta, omega);
        MultiplyTridiagonalMatrix(n, p_nu, pA, p_p);
        alpha = rho1/InnerProduct(n, p_rhat, p_nu);
        CalculateH(n, p_h, p_x, alpha, p_p);

        // Step 7
        if(CheckEarlyBreak(n, pb, pA, p_h, tol))
        {
            std::cout << "exit here" << std::endl;
            CopyVector(n, p_h, p_x);
            break;
        }

        // Steps 8-12
        CalculateS(n, p_s, p_r, alpha, p_nu);
        MultiplyTridiagonalMatrix(n, p_t, pA, p_s);
        omega = InnerProduct(n, p_t, p_s)/InnerProduct(n, p_t, p_t);
        CalculateX(n, p_x, p_h, omega, p_s);
        CalculateR(n, p_r, p_s, omega, p_t);
        
        norm = Norm2(n, p_r);
        std::cout <<  counter << ", norm = " << norm << std::endl;

        rho0 = rho1;

        counter++;

    } while (norm > tol && counter < maxIter);

    CopyVector(n, p_x, pxEstimate);

    delete[] p_r, p_rhat, p_p, p_nu, p_h, p_s, p_t, p_x;
}

void CalculateR0(int n, double* pr0, double* pb, double** pA, double* px0)
{
    double* p_a;
    p_a = new double[n];

    MultiplyTridiagonalMatrix(n, p_a, pA, px0);
    Subtract(n, pr0, pb, p_a);

    delete[] p_a;
}

bool CheckEarlyBreak(int n, double* pb, double** pA, double* ph, double tol)
{
    double* p_a;
    p_a = new double[n];

    MultiplyTridiagonalMatrix(n, p_a, pA, ph);
    Subtract(n, p_a, pb, p_a);
    double difference = Norm2(n, p_a);

    delete[] p_a;

    if(difference > tol)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void CalculateP(int n, double* pp, double* pr, double* pNu, double beta, 
                double omega)
{
    double* p_a;
    p_a = new double[n];

    ScaleVector(n, p_a, omega, pNu);
    Subtract(n, p_a, pp, p_a);
    ScaleVector(n, p_a, beta, p_a);
    Add(n, pp, pr, p_a);

    delete[] p_a;
}

void CalculateH(int n, double* ph, double* px, double alpha, double* pp)
{
    double* p_a;
    p_a = new double[n];

    ScaleVector(n, p_a, alpha, pp);
    Add(n, ph, px, p_a);

    delete[] p_a;
}

void CalculateS(int n, double* ps, double* pr, double alpha, double* pNu)
{
    double* p_a;
    p_a = new double[n];

    ScaleVector(n, p_a, alpha, pNu);
    Subtract(n, ps, pr, p_a);

    delete[] p_a;
}

void CalculateX(int n, double* px, double* ph, double omega, double* ps)
{
    double* p_a;
    p_a = new double[n];

    ScaleVector(n, p_a, omega, ps);
    Add(n, px, ph, p_a);

    delete[] p_a;
}

void CalculateR(int n, double* pr, double* ps, double omega, double* pt)
{
    double* p_a;
    p_a = new double[n];

    ScaleVector(n, p_a, omega, pt);
    Subtract(n, pr, ps, p_a);

    delete[] p_a;
}
