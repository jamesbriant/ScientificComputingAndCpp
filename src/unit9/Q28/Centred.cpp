#include <cassert>
#include <iostream>
#include "Centred.hpp"

Centred::Centred(const double Xval, const double Hval, 
                 double (*pUserFunction)(double))
{
    mXval = Xval;
    assert(Hval > 0);
    mHval = Hval;
    mpFunction = pUserFunction;
}

double Centred::Differentiate() const
{
    double a = mpFunction(mXval + mHval) - mpFunction(mXval - mHval);
    return a/(2.0*mHval);
}

void Centred::PrintDifferentiate() const
{
    std::cout << "dy/dx = " << Differentiate() << std::endl;
}