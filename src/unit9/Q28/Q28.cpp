#include <iostream>
#include <cmath>
#include "OneSided.hpp"
#include "Centred.hpp"

// g++ Q28.cpp OneSided.cpp Centred.cpp -o Q28.exe

double f1(double x);
double f2(double x);
double f3(double x);

int main(int argc, char* argv[])
{
    double x = 1.0;
    double h = 10.0e-5;

    std::cout << "OneSided:" << std::endl;
    OneSided OS1(x, h, &f1);
    std::cout << OS1.Differentiate() << std::endl;
    OneSided OS2(x, h, &f2);
    std::cout << OS2.Differentiate() << std::endl;
    OneSided OS3(x, h, &f3);
    std::cout << OS3.Differentiate() << std::endl;

    std::cout << "Centred:" << std::endl;
    Centred C1(x, h, &f1);
    std::cout << C1.Differentiate() << std::endl;
    Centred C2(x, h, &f2);
    std::cout << C2.Differentiate() << std::endl;
    Centred C3(x, h, &f3);
    std::cout << C3.Differentiate() << std::endl;

    return 0;
}

double f1(double x)
{
    return pow(x, 3);
}

double f2(double x)
{
    return sin(2.0*x);
}

double f3(double x)
{
    return pow(x, -1.0/3.0);
}