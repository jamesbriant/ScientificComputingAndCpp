#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include "functions.hpp"

// I compile this by using `g++ main.cpp functions.cpp -o main.exe`

int main(int argc, char* argv[])
{
    int n;
    if(argc != 2)
    {
        std::cout << "Enter a value n: " << std::endl;
        std::cin >> n;
    }
    else
    {
        n = atoi(argv[1]);
    }
    

    double** A = AllocateUpperTriangular(n);
    PopulateUpperTriangular(n, A);

    long double trace = FrobeniusNorm(n, A);

    std::cout << "The Frobenius norm is: ";
    std::cout << sqrt(trace);

    DeallocateSquareMatrix(n, A);

    return 0;
}
