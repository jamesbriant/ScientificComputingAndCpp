#include <iostream>
#include <cmath>
#include "include/general.hpp"
#include "include/quadrature.hpp"

double f(double x);

// I compile this by using 
// `g++ Q1c.cpp source/general.cpp source/quadrature.cpp -o Q1c.exe`

int main(int argc, char* argv[])
{
    int n1 = 5;
    //int N1 = 2*n1 + 1;
    int n2 = 10;
    //int N2 = 2*n2 + 1;
    int n3 = 20;
    //int N3 = 2*n3 + 1;

    double a = 0.0;
    double b = 1.0;

    double I1 = ApplySimpsonsRule(n1, a, b, &f);
    double I2 = ApplySimpsonsRule(n2, a, b, &f);
    double I3 = ApplySimpsonsRule(n3, a, b, &f);

    double I0 = 1/ M_PI;

    std::cout << "n = " << n1 << ", error = " << fabs(I1 - I0) << std::endl;
    std::cout << "n = " << n2 << ", error = " << fabs(I2 - I0) << std::endl;
    std::cout << "n = " << n3 << ", error = " << fabs(I3 - I0) << std::endl;

    std::cout << "All estimates are very accurate with the worst estimate only";
    std::cout << " differing from the true solution at the 5th decimal place. ";
    std::cout << "This shows ";

    return 0;
}

double f(double x)
{
    return x*sin(M_PI * x);
}


























