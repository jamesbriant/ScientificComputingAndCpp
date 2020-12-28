#include <iostream>
#include <cmath>
#include "OneSided.hpp"
#include "Centred.hpp"
#include "DerivativeInterface.hpp"
#include "CubicPolynomial.hpp"

// g++ Q29.cpp AbstractDifferentiator.cpp Centred.cpp CubicPolynomial.cpp DerivativeInterface.cpp OneSided.cpp -o Q29.exe

double f1(double x);

int main(int argc, char* argv[])
{
    double x = 1.0;
    double h = 10.0e-5;

    DerivativeInterface* p_cubic = new CubicPolynomial();

    std::cout << "OneSided:" << std::endl;
    OneSided* p_one_sided = new OneSided(x, h, *p_cubic);
    std::cout << p_one_sided->Differentiate() << std::endl;
    p_one_sided->PrintDerivativeError(p_one_sided->Differentiate());

    std::cout << "Centred:" << std::endl;
    Centred* p_centred = new Centred(x, h, *p_cubic);
    std::cout << p_centred->Differentiate() << std::endl;
    p_one_sided->PrintDerivativeError(p_one_sided->Differentiate());

    delete p_cubic, p_one_sided, p_centred;

    return 0;
}

double f1(double x)
{
    return pow(x, 3);
}