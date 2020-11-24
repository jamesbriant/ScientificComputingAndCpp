#include <iostream>
#include <cmath>
#include "general.hpp"
#include "quadrature.hpp"

double f(double x);

int main(int argc, char* argv[])
{
    // Define question parameters
    int n5 = 5;
    int n10 = 10;
    int n20 = 20;

    double a = 0.0;
    double b = 1.0;

    // Call the integration algorithm
    double I5 = ApplySimpsonsRule(n5, a, b, &f);
    double I10 = ApplySimpsonsRule(n10, a, b, &f);
    double I20 = ApplySimpsonsRule(n20, a, b, &f);

    // Analytical (true) solution
    double I0 = 1/ M_PI;

    // Calculate and print the errors
    std::cout << "n=" << n5 << ", Approximation=" << I5;
    std::cout << ", Error=" << fabs(I5 - I0) << std::endl;
    std::cout << "n=" << n10 << ", Approximation=" << I10;
    std::cout << ", Error=" << fabs(I10 - I0) << std::endl;
    std::cout << "n=" << n20 << ", Approximation=" << I20;
    std::cout << ", Error=" << fabs(I20 - I0) << std::endl;

    std::cout << "All estimates are very accurate with the worst estimate only";
    std::cout << " differing from the true solution at the 5th decimal place. ";
    std::cout << "Increasing the number of nodal points decreases the error ";
    std::cout << "as expected.";

    return 0;
}

double f(double x)
// locally defined function specific to this question
{
    return x*sin(M_PI * x);
}


























