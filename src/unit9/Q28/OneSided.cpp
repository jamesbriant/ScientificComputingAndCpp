#include <cassert>
#include <iostream>
#include "OneSided.hpp"

OneSided::OneSided(const double Xval, const double Hval, 
                 double (*pUserFunction)(double))
{
    mXval = Xval;
    assert(Hval > 0);
    mHval = Hval;
    mpFunction = pUserFunction;
}

double OneSided::Differentiate() const
{
    double a = mpFunction(mXval + mHval) - mpFunction(mXval);
    return a/mHval;
}

void OneSided::PrintDifferentiate() const
{
    std::cout << "dy/dx = " << Differentiate() << std::endl;
}