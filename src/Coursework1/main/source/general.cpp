#include <stdlib.h>
#include <iostream>
#include <cmath>

void CopyVector(int length, double* pVec, double* pNewVec)
// Copies data stored at vec in to newVec
{
    for (int k=0;k<length;k++)
    {
        pNewVec[k] = pVec[k];
    }
}

void PrintVector(int length, double* pVec)
// Prints out the data stored in vec
{
    for(int i=0; i<length; i++)
    {
        std::cout << pVec[i] << std::endl;
    }
}

void PrintMatrix(int p, int q, double** pMatrix)
// Prints out the data stored in vec
{
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<q; j++)
        {
            std::cout << pMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

double** AllocateMatrix(int nrows, int ncols)
// Allocates matrix of size nrows x ncols
// Note this does NOT populate the matrix
{
    double** p_A;
    p_A = new double* [nrows];
    for(int i=0; i<nrows; i++)
    {
        p_A[i] = new double [ncols];
    }

    return p_A;
}

double** AllocateTridiagonalMatrix(int nrows)
// Alloccates matrix of size nrows x 3, but with first and last row of length 2
// Note this does NOT populate the matrix
{
    double** p_A;
    p_A = new double* [nrows];
    p_A[0] = new double [2];
    for(int i=1; i<nrows-1; i++)
    {
        p_A[i] = new double [3];
    }
    p_A[nrows-1] = new double [2];

    return p_A;
}

void PopulateMatrix(int nrows, int ncols, double** pMatrix)
// Populates the matrix with random values in (0,1)
// Requires a predefined matrix as an input
{
    for(int i=0; i<nrows; i++)
    {
        for(int j=0; j<ncols; j++)
        {
            pMatrix[i][j] = ((double) rand() / (RAND_MAX));
        }
    }
}

void PopulateVector(int nrows, double* pVector)
// Populates the vector with random values in (0,1)
// Requires a predefined vector as an input
{
    for(int i=0; i<nrows; i++)
    {
        pVector[i] = ((double) rand() / (RAND_MAX));
    }
}

void PopulateVector0(int nrows, double* pVector)
// Populates the vector with zeros
// Requires a predefined vector as an input
{
    for(int i=0; i<nrows; i++)
    {
        pVector[i] = 0;
    }
}

void Multiply(int nrows, double* pMx, int ncols, double** pM, double* px)
// Overloaded function
// returns the matrix product of a matrix M and a vector x, Mx
{
    double sum;

    for(int i=0; i<nrows; i++)
    {
        sum = 0;

        for(int j=0; j<ncols; j++)
        {
            sum += pM[i][j] * px[j];
        }

        pMx[i] = sum;
    }
}

void Multiply(int nrows, double* pxM, int ncols, double* px, double** pM)
// Overloaded function
// returns the matrix product of a vector x and a matrix M, xM
{
    double sum;

    for(int i=0; i<ncols; i++)
    {
        sum = 0;

        for(int j=0; j<nrows; j++)
        {
            sum += pM[i][j] * px[j];
        }

        pxM[i] = sum;
    }
}

void MultiplyTridiagonalMatrix(int nrows, double* pMx, double** pM, double* px)
// Calculates the matrix product of tridiagonal matrix M and a vector x,
// Saves result to pMx
{
    // calculate end points of output array 
    pMx[0] = pM[0][0]*px[0] + pM[0][1]*px[1];
    pMx[nrows-1] = pM[nrows-1][0]*px[nrows-2] + pM[nrows-1][1]*px[nrows-1];

    double sum;

    // calculate middle points of output array
    for(int i=1; i<nrows-1; i++)
    {
        sum = 0;

        for(int j=0; j<3; j++)
        {
            sum += pM[i][j] * px[i-1+j]; //adjusts for 0's in the tridiagonal
        }

        pMx[i] = sum;
    }
}

void Add(int n, double* pSum, double* pa, double* pb)
// Adds vector b to vector a
{
    for(int i=0; i<n; i++)
    {
        pSum[i] = pa[i] + pb[i];
    }
}

void Subtract(int n, double* pDiff, double* pa, double* pb)
// Subtracts vector b from vector a
// diff = a-b
{
    for(int i=0; i<n; i++)
    {
        pDiff[i] = pa[i] - pb[i];
    }
}

void ScaleVector(int n, double* pScaledVec, double a, double* pVec)
// Returns a*pVec
{
    for(int i=0; i<n; i++)
    {
        pScaledVec[i] = a*pVec[i];
    }
}

double InnerProduct(int n, double* pVec1, double* pVec2)
// Returns the inner product of the vectors pVec1 and pVec2
{
    double sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += pVec1[i]*pVec2[i];
    }

    return sum;
}

double Norm2(int n, double* pVec)
// Returns the 2-norm of pVec
{
    return sqrt(InnerProduct(n, pVec, pVec));
}

void DeallocateMatrix(int nrows, double** pMatrix)
// Deletes the matrix provided
{
    for(int i=0; i<nrows; i++)
    {
        delete[] pMatrix[i];
    }

    delete[] pMatrix;
}
