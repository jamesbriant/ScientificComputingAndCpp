#include <cmath>
#include <fstream>
#include "fem.hpp"
#include "general.hpp"
#include "quadrature.hpp"
#include "linear_algebra.hpp"

double* GenerateFEMMesh(double a, double b, int N)
// Generates N+1 nodal points on (a,b)
{
    double* p_mesh;
    p_mesh = new double[N+1];

    double h = (b-a)/N;

    for(int i=0; i<=N; i++)
    {
        p_mesh[i] = a + h*i;
    }

    return p_mesh;
}

double CalculatePhiValue(int k, double x, double h, double a, bool derivative)
// Calculates the local Phi values.
// Calculates derivative if derivative = true.
{
    if(k == 0)
    {
        if(derivative == true)// returns the derivative of phi0(x)
        {
            return -1/h;
        }

        return 1-(x-a)/h; // return phi0(x)
    }
    else
    {
        if(derivative == true) // returns the derivative of phi1(x)
        {
            return 1/h;
        }

        return (x-a)/h; // return phi1(x)
    }
}

void SetupStiffnessAndLoadArrays(int n, double** pA, double* pF, double* pMesh, 
        double A, double B, double (*b)(double x), double (*c)(double x),
        double (*f)(double x))
// n is the size of the matrix A. So pMesh is of length n+1
{
    // Define the mesh size for the quadrature algorithm
    int N = 10;

    ////////////////////////////
    // Generate A

    double A_00_b, A_00_c, A_00;
    double A_01_b, A_01_c, A_01;
    double A_10_b, A_10_c, A_10;
    double A_11_b, A_11_c, A_11;

    // Set the first row of pA
    A_11_b = ApplySimpsonsRule(N, pMesh[0], pMesh[1], &Integrand11b, b);
    A_11_c = ApplySimpsonsRule(N, pMesh[0], pMesh[1], &Integrand11c, c);
    A_11 = A_11_b + A_11_c;
    A_00_b = ApplySimpsonsRule(N, pMesh[1], pMesh[2], &Integrand00b, b);
    A_00_c = ApplySimpsonsRule(N, pMesh[1], pMesh[2], &Integrand00c, c);
    A_00 = A_00_b + A_00_c;
    pA[0][0] = A_11 + A_00;
    A_01_b = ApplySimpsonsRule(N, pMesh[1], pMesh[2], &Integrand01b, b);
    A_01_c = ApplySimpsonsRule(N, pMesh[1], pMesh[2], &Integrand01c, c);
    A_01 = A_01_b + A_01_c;
    pA[0][1] = A_01;

    // Set the final row of pA
    A_10_b = ApplySimpsonsRule(N, pMesh[n-1], pMesh[n], &Integrand10b, b);
    A_10_c = ApplySimpsonsRule(N, pMesh[n-1], pMesh[n], &Integrand10c, c);
    A_10 = A_10_b + A_10_c;
    pA[n-1][0] = A_10;
    A_11_b = ApplySimpsonsRule(N, pMesh[n-1], pMesh[n], &Integrand11b, b);
    A_11_c = ApplySimpsonsRule(N, pMesh[n-1], pMesh[n], &Integrand11c, c);
    A_11 = A_11_b + A_11_c;
    A_00_b = ApplySimpsonsRule(N, pMesh[n], pMesh[n+1], &Integrand00b, b);
    A_00_c = ApplySimpsonsRule(N, pMesh[n], pMesh[n+1], &Integrand00c, c);
    A_00 = A_00_b + A_00_c;
    pA[n-1][1] = A_11 + A_00;

    // Fill in the middle of the matrix, pA
    // one row at a time (NOT using the A-hat from the notes)
    for(int i=1; i<n-1; i++)
    {
        A_10_b = ApplySimpsonsRule(N, pMesh[i], pMesh[i+1], &Integrand10b, b);
        A_10_c = ApplySimpsonsRule(N, pMesh[i], pMesh[i+1], &Integrand10c, c);
        A_10 = A_10_b + A_10_c;
        pA[i][0] = A_10;

        A_11_b = ApplySimpsonsRule(N, pMesh[i], pMesh[i+1], &Integrand11b, b);
        A_11_c = ApplySimpsonsRule(N, pMesh[i], pMesh[i+1], &Integrand11c, c);
        A_11 = A_11_b + A_11_c;
        A_00_b = ApplySimpsonsRule(N, pMesh[i+1], pMesh[i+2], &Integrand00b, b);
        A_00_c = ApplySimpsonsRule(N, pMesh[i+1], pMesh[i+2], &Integrand00c, c);
        A_00 = A_00_b + A_00_c;
        pA[i][1] = A_11 + A_00;

        A_01_b = ApplySimpsonsRule(N, pMesh[i+1], pMesh[i+2], &Integrand01b, b);
        A_01_c = ApplySimpsonsRule(N, pMesh[i+1], pMesh[i+2], &Integrand01c, c);
        A_01 = A_01_b + A_01_c;
        pA[i][2] = A_01;
    }

    //////////////////////
    //  Genereate F
    double F0, F1;

    // Fill in middle of pF
    for(int i=0; i<n; i++)
    {
        F1 = ApplySimpsonsRule(N, pMesh[i], pMesh[i+1], &IntegrandEll1, f);
        F0 = ApplySimpsonsRule(N, pMesh[i+1], pMesh[i+2], &IntegrandEll0, f);
        pF[i] = F1 + F0;
    }
    
    // Adjust for boundary conditions
    A_00_b = ApplySimpsonsRule(N, pMesh[0], pMesh[1], &Integrand00b, b);
    A_00_c = ApplySimpsonsRule(N, pMesh[0], pMesh[1], &Integrand00c, c);
    pF[0] -= A*(A_00_b + A_00_c);

    A_10_b = ApplySimpsonsRule(N, pMesh[0], pMesh[1], &Integrand10b, b);
    A_10_c = ApplySimpsonsRule(N, pMesh[0], pMesh[1], &Integrand10c, c);
    pF[1] -= A*(A_10_b + A_10_c);

    A_01_b = ApplySimpsonsRule(N, pMesh[n-1], pMesh[n], &Integrand01b, b);
    A_01_c = ApplySimpsonsRule(N, pMesh[n-1], pMesh[n], &Integrand01c, c);
    pF[n-2] -= B*(A_01_b + A_01_c);

    A_11_b = ApplySimpsonsRule(N, pMesh[n-1], pMesh[n], &Integrand11b, b);
    A_11_c = ApplySimpsonsRule(N, pMesh[n-1], pMesh[n], &Integrand11c, c);
    pF[n-1] -= B*(A_11_b + A_11_c);
    
}

double Integrand00b(double x, double h, double a, double (*b)(double x))
// k=0, j=0
{
    double phi0 = CalculatePhiValue(0, x, h, a, false);
    double phi0prime = CalculatePhiValue(0, x, h, a, true);
    
    return phi0prime*(phi0prime + (*b)(x)*phi0);
}

double Integrand00c(double x, double h, double a, double (*c)(double x))
// k=0, j=0
{
    double phi0 = CalculatePhiValue(0, x, h, a, false);

    return (*c)(x)*phi0*phi0;
}

double Integrand01b(double x, double h, double a, double (*b)(double x))
// k=0, j=1
{
    double phi0 = CalculatePhiValue(0, x, h, a, false);
    double phi0prime = CalculatePhiValue(0, x, h, a, true);
    double phi1prime = CalculatePhiValue(1, x, h, a, true);
    
    return phi1prime*(phi0prime + (*b)(x)*phi0);
}

double Integrand01c(double x, double h, double a, double (*c)(double x))
// k=0, j=1
{
    double phi0 = CalculatePhiValue(0, x, h, a, false);
    double phi1 = CalculatePhiValue(1, x, h, a, false);

    return (*c)(x)*phi0*phi1;
}

double Integrand10b(double x, double h, double a, double (*b)(double x))
// k=1, j=0
{
    double phi1 = CalculatePhiValue(1, x, h, a, false);
    double phi0prime = CalculatePhiValue(0, x, h, a, true);
    double phi1prime = CalculatePhiValue(1, x, h, a, true);
    
    return phi0prime*(phi1prime + (*b)(x)*phi1);
}

double Integrand10c(double x, double h, double a, double (*c)(double x))
// k=1, j=0
{
    double phi0 = CalculatePhiValue(0, x, h, a, false);
    double phi1 = CalculatePhiValue(1, x, h, a, false);

    return (*c)(x)*phi0*phi1;
}

double Integrand11b(double x, double h, double a, double (*b)(double x))
// k=1, j=1
{
    double phi1 = CalculatePhiValue(1, x, h, a, false);
    double phi1prime = CalculatePhiValue(1, x, h, a, true);
    
    return phi1prime*(phi1prime + (*b)(x)*phi1);
}

double Integrand11c(double x, double h, double a, double (*c)(double x))
// k=1, j=1
{
    double phi1 = CalculatePhiValue(1, x, h, a, false);

    return (*c)(x)*phi1*phi1;
}

double IntegrandEll0(double x, double h, double a, double (*f)(double x))
// k=0
{
    double phi0 = CalculatePhiValue(0, x, h, a, false);

    return phi0 * (*f)(x);
}

double IntegrandEll1(double x, double h, double a, double (*f)(double x))
// k=1
{
    double phi1 = CalculatePhiValue(1, x, h, a, false);

    return phi1 * (*f)(x);
}

void CalculateU(int n, double* puEstimate, double** pA, double* pu0, 
        double* pF, double tol, int maxIter)
// Uses method from Q2 to solve the system of equations
{
    ApplyBiGCstab(n, puEstimate, pA, pu0, pF, tol, maxIter);
}

double* CalculateUh(int n, double A, double B, double* pU)
// calculates the u_h(x) approximation to u(x) at the FEM mesh points
{
    double* p_Solution;
    p_Solution = new double[n+2];

    // Add boundary points to solution
    p_Solution[0] = A;
    p_Solution[n+1] = B;

    // Fill in middle of solution
    for(int i=0; i<n; i++)
    {
        p_Solution[i+1] = pU[i];
    }

    return p_Solution;
}

void SaveData(int n, double* pMesh, double* pSolution)
// Saves the solution data to a file called ODESolution.dat
{  
    std::ofstream writeFile("ODESolution.dat");

    for(int i=0; i<n; i++)
    {
        writeFile << pMesh[i] << " " << pSolution[i] << "\n";
    }

    writeFile.close();
}