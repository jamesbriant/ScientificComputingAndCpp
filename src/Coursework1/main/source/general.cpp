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
// Alocates matrix of size nrows x ncols
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

double* Multiply(int nrows, int ncols, double** pM, double* px)
// Overloaded function
// returns the matrix product of a matrix M and a vector x, Mx
{
    double* p_Mx;
    p_Mx = new double[nrows];

    for(int i=0; i<nrows; i++)
    {
        double sum = 0;

        for(int j=0; j<ncols; j++)
        {
            sum += pM[i][j] * px[j];
        }

        p_Mx[i] = sum;
    }

    return p_Mx;
}

double* Multiply(int nrows, int ncols, double* px, double** pM)
// Overloaded function
// returns the matrix product of a vector x and a matrix M, xM
{
    double* p_xM;
    p_xM = new double[ncols];

    for(int i=0; i<ncols; i++)
    {
        double sum = 0;

        for(int j=0; j<nrows; j++)
        {
            sum += pM[i][j] * px[j];
        }

        p_xM[i] = sum;
    }

    return p_xM;
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
