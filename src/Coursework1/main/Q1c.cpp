#include <iostream>
#include <cmath>
#include "include/general.hpp"
#include "include/quadrature.hpp"

double f(double x);

// I compile this by using 
// `g++ Q1c.cpp source/general.cpp source/quadrature.cpp -o Q1c.exe`

int main(int argc, char* argv[])
{
    int n5 = 5;
    int n10 = 10;
    int n20 = 20;

    double a = 0.0;
    double b = 1.0;

    double I5 = ApplySimpsonsRule(n5, a, b, &f);
    double I10 = ApplySimpsonsRule(n10, a, b, &f);
    double I20 = ApplySimpsonsRule(n20, a, b, &f);

    double I0 = 1/ M_PI;

    std::cout << "n = " << n5 << ", error = " << fabs(I5 - I0) << std::endl;
    std::cout << "n = " << n10 << ", error = " << fabs(I10 - I0) << std::endl;
    std::cout << "n = " << n20 << ", error = " << fabs(I20 - I0) << std::endl;

    std::cout << "All estimates are very accurate with the worst estimate only";
    std::cout << " differing from the true solution at the 5th decimal place. ";
    std::cout << "This shows ";

    return 0;
}

double f(double x)
{
    return x*sin(M_PI * x);
}


























