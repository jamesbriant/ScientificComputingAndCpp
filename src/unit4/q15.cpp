#include <iostream>
#include <stdlib.h>

double* MultiplyMatrixVector(int n, int m, double** M, double* x);

int main()
{
    int n=5, m=7;

    double** matrix;
    matrix = new double*[n];
    for(int i=0; i<n; i++)
    {
        matrix[i] = new double[m];

        for(int j=0; j<m; j++)
        {
            matrix[i][j] = ((double) rand() / (RAND_MAX));
        }
    }

    double* vector;
    vector = new double[m];
    for(int i=0; i<m; i++)
    {
        vector[i] = ((double) rand() / (RAND_MAX));
    }

    // Compute the multiplication
    double* output;
    output = new double[n];
    output = MultiplyMatrixVector(n, m, matrix, vector);

    // Output the multiplication
    for(int i=0; i<n; i++)
    {
        std::cout << output[i] << " ";
    }


    // Delete the arrays
    for(int i=0; i<n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix, vector;

    return 0;
}

double* MultiplyMatrixVector(int n, int m, double** M, double* x)
{
    double* Mx;
    Mx = new double[n];

    for(int i=0; i<n; i++)
    {
        double sum = 0;

        for(int j=0; j<m; j++)
        {
            sum += M[i][j] * x[j];
        }

        Mx[i] = sum;
    }

    return Mx;
}