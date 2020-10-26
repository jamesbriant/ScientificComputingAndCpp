#include <stdlib.h>
#include <cmath>

double** AllocateMatrix(int nrows, int ncols)
{
    double** A;
    A = new double* [nrows];
    for(int i=0; i<nrows; i++)
    {
        A[i] = new double [ncols];
    }

    return A;
}

int PopulateMatrix(int nrows, int ncols, double** matrix)
{
    for(int i=0; i<nrows; i++)
    {
        for(int j=0; j<ncols; j++)
        {
            matrix[i][j] = ((double) rand() / (RAND_MAX));
        }
    }

    return 0;
}

double* Multiply(int nrows, int ncols, double** M, double* x)
{
    double* Mx;
    Mx = new double[nrows];

    for(int i=0; i<nrows; i++)
    {
        double sum = 0;

        for(int j=0; j<ncols; j++)
        {
            sum += M[i][j] * x[j];
        }

        Mx[i] = sum;
    }

    return Mx;
}

double* Multiply(int nrows, int ncols, double* x, double** M)
{
    double* xM;
    xM = new double[ncols];

    for(int i=0; i<ncols; i++)
    {
        double sum = 0;

        for(int j=0; j<nrows; j++)
        {
            sum += M[i][j] * x[j];
        }

        xM[i] = sum;
    }

    return xM;
}

void DeallocateMatrix(int nrows, double** matrix)
{
    for(int i=0; i<nrows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}
