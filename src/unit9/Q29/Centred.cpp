#include <cassert>
#include <iostream>
#include "Centred.hpp"
#include "DerivativeInterface.hpp"

Centred::Centred(const double Xval, const double Hval, 
                 DerivativeInterface& pUserFunction)
{
    mXval = Xval;
    assert(Hval > 0);
    mHval = Hval;
    mpFunction = &pUserFunction;
}

double Centred::Differentiate() const
{
    double a = mpFunction->ComputeFunction(mXval + mHval) - mpFunction->ComputeFunction(mXval - mHval);
    return a/(2.0*mHval);
}

void Centred::PrintDifferentiate() const
{
    std::cout << "dy/dx = " << Differentiate() << std::endl;
}