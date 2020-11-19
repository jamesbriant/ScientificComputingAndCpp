#include <iostream>
#include <cmath>
#include "general.hpp"
#include "linear_algebra.hpp"

void PopulateA(int nrows, double** pA);

int main(int argc, char* argv[])
{
    //int n = atoi(argv[1]);
    double tol = 1e-9;
    int maxIter = 1000;

    for(int i=1; i<=5; i++)
    {
        int n = pow(10, i);

        double** A;
        A = AllocateTridiagonalMatrix(n);
        PopulateA(n, A);

        double* x;
        double* x0;
        double* xEstimate;
        double* b;
        x = new double[n];
        x0 = new double[n];
        xEstimate = new double[n];
        b = new double[n];
        PopulateVector(n, x);
        PopulateVector(n, x0);
        MultiplyTridiagonalMatrix(n, b, A, x);

        ApplyBiGCstab(n, xEstimate, A, x0, b, tol, maxIter);
        //PrintVector(n, xEstimate);

        DeallocateMatrix(n, A);
        delete[] x, x0, xEstimate, b;
    }

    //std::cin.get();

    return 0;
}

void PopulateA(int nrows, double** pA)
// Populates the matrix, pA, with the values required in the question
// Requires a predefined matrix as an input
{
    double j;
    double J = (double)((nrows - 1) % 2);

    // calculate end points of output array 
    pA[0][0] = 1.0;
    pA[0][1] = 0.0;
    pA[nrows-1][0] = -1.0 - J;
    pA[nrows-1][1] = 1.0 + J;
    
    // calculate middle points of output array
    for(int i=1; i<nrows-1; i++)
    {
        j = (double)(i % 2);

        pA[i][0] = -1.0 - j;
        pA[i][1] = 1.0 + j;
        pA[i][2] = j;
    }
}

























