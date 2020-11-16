#include <cmath>
#include "../include/linear_algebra.hpp"
#include "../include/general.hpp"

double* ApplyBiGCstab(int n, double** pA, double* px0, double* pb, double tol,
                      int maxIter)
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
    CopyVector(n, Subtract(n, pb, MultiplyTridiagonalMatrix(n, pA, px0)), p_r);
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
    double* p_h;
    double* p_s;
    double* p_t;
    p_h = new double[n];
    p_s = new double[n];
    p_t = new double[n];

    int counter = 0;
    
    // Algorithm implementation
    do
    {
        rho1 = InnerProduct(n, p_rhat, p_r);
        beta = (rho1*alpha)/(rho0*omega);
        p_p = CalculateP(n, p_r, p_p, p_nu, beta, omega);
        p_nu = MultiplyTridiagonalMatrix(n, pA, p_p);
        alpha = rho1/InnerProduct(n, p_rhat, p_nu);
        p_h = Add(n, p_x, ScaleVector(n, alpha, p_p));

        if(Norm2(n, Subtract(n, pb, MultiplyTridiagonalMatrix(n, pA, p_h))) < tol)
        {
            CopyVector(n, p_h, p_x);
            break;
        }

        p_s = Subtract(n, p_r, ScaleVector(n, alpha, p_nu));
        p_t = MultiplyTridiagonalMatrix(n, pA, p_s);
        omega = InnerProduct(n, p_t, p_s)/InnerProduct(n, p_t, p_t);
        p_x = Add(n, p_h, ScaleVector(n, omega, p_s));
        p_r = Subtract(n, p_s, ScaleVector(n, omega, p_t));

        counter++;

    } while (Norm2(n, p_r) < tol && counter < maxIter);

    delete[] p_r, p_rhat, p_p, p_nu, p_h, p_s, p_t;

    return p_x;
}

double* CalculateP(int n, double* pR, double* pP, double* pNu, double beta, 
                    double omega)
{
    double* p_a;
    p_a = new double[n];
    CopyVector(n, ScaleVector(n, omega, pNu), p_a);
    p_a = Subtract(n, pP, p_a);
    p_a = ScaleVector(n, beta, p_a);
    p_a = Add(n, pR, p_a);

    return p_a;
}



