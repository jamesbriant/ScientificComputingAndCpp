#include <cmath>
#include "../include/linear_algebra.hpp"
#include "../include/general.hpp"

double* ApplyBiGCstab(int n, double** pA, double* px0, double* pb, double tol)
// Returns solution to Ax=b where A is a known tridiagonal matrix and b is known
// Uses the biconjugate gradient stabilised method.
{
    // Set up r and rhat
    double* p_rhat;
    double* p_r;
    p_rhat = new double[n];
    p_r = new double[n];
    CopyVector(n, Subtract(n, pb, MultiplyTridiagonalMatrix(n, pA, px0)), p_r);
    CopyVector(n, p_r, p_rhat);

    // Set up p and nu
    double* p;
    double* nu;
    p = new double[n];
    nu = new double[n];
    PopulateVector0(n, p);
    PopulateVector0(n, nu);

    // Set up rho, alpha and omega
    double rho = 1;
    double alpha = 1;
    double omega = 1;

    delete[] p_r, p_rhat, p, nu;
}

double* CalculateR(int n, double** pA, double* px0, double* pb)
{
    return Subtract(n, pb, MultiplyTridiagonalMatrix(n, pA, px0));
}



