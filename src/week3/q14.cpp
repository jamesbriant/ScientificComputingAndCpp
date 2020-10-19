#include <iostream>
#include <stdlib.h>
#include <cmath>

int main()
{
    int n;
    std::cout << "Enter a value n: " << std::endl;
    std::cin >> n;

    double** A;
    A = new double* [n];
    for(int i=0; i<n; i++)
    {
        A[i] = new double [n-i];
        
        for(int j=0; j<(n-i); j++)
        {
            A[i][j] = ((double) rand() / (RAND_MAX));
        }
    }

    long double trace = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<(n-i); j++)
        {
            trace += pow(A[i][j], 2);
        }
    }

    std::cout << "The Frobenius norm is: ";
    std::cout << sqrt(trace);

    delete A;

    return 0;
}