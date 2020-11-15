#include <iostream>
#include <cmath>
#include "include/general.hpp"
#include "include/quadrature.hpp"

double f(double x);

// I compile this by using 
// `g++ Q1c.cpp source/general.cpp source/quadrature.cpp -o Q1c.exe`

int main(int argc, char* argv[])
{
    int n = 5;
    int N = 2*n + 1;
    double a = 0.0;
    double b = 1.0;

    double approximation = ApplySimpsonsRule(n, a, b, &f);

    std::cout << 1/approximation;

    return 0;
}

double f(double x)
{
    return x*sin(M_PI * x);
}


























