#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include "functions.hpp"

// I compile this by using `g++ main.cpp functions.cpp -o main.exe`

int main(int argc, char* argv[])
{
    int n=3, m=2;

    double** A = AllocateMatrix(n, m);
    PopulateMatrix(n, m, A);

    double* rowVector;
    rowVector = new double[m];
    for(int i=0; i<m; i++)
    {
        rowVector[i] = ((double) rand() / (RAND_MAX));
    }

    double* colVector;
    colVector = new double[n];
    for(int i=0; i<n; i++)
    {
        colVector[i] = ((double) rand() / (RAND_MAX));
    }

    double* output1;
    double* output2;
    output1 = new double[m];
    output2 = new double[n];

    output1 = Multiply(n, m, rowVector, A);
    output2 = Multiply(n, m, A, colVector);

    std::cout << output1[0] << " " << output1[1] << std::endl;
    std::cout << output2[0] << " " << output2[1] << " " << output2[2];

    DeallocateMatrix(n, A);
    delete[] rowVector, colVector, output1, output2;

    return 0;
}
