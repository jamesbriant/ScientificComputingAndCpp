#include <stdlib.h>
#include <cmath>

double** AllocateUpperTriangular(int nrows)
{
    double** A;
    A = new double* [nrows];
    for(int i=0; i<nrows; i++)
    {
        A[i] = new double [nrows-i];
    }

    return A;
}

int PopulateUpperTriangular(int nrows, double** matrix)
{
    for(int i=0; i<nrows; i++)
    {
        for(int j=0; j<nrows-i; j++)
        {
            matrix[i][j] = ((double) rand() / (RAND_MAX));
        }
    }

    return 0;
}

void DeallocateSquareMatrix(int nrows, double** matrix)
{
    for(int i=0; i<nrows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

long double FrobeniusNorm(int nrows, double** matrix)
{
    long double trace = 0;

    for(int i=0; i<nrows; i++)
    {
        for(int j=0; j<(nrows-i); j++)
        {
            trace += pow(matrix[i][j], 2);
        }
    }

    return trace;
}