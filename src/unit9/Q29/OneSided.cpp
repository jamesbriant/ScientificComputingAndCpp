#include <cassert>
#include <iostream>
#include "OneSided.hpp"
#include "DerivativeInterface.hpp"

OneSided::OneSided(const double Xval, const double Hval, 
                   DerivativeInterface& pUserFunction)
{
    mXval = Xval;
    assert(Hval > 0);
    mHval = Hval;
    mpFunction = &pUserFunction;
}

double OneSided::Differentiate() const
{
    double a = mpFunction->ComputeFunction(mXval + mHval) - mpFunction->ComputeFunction(mXval);
    return a/mHval;
}

void OneSided::PrintDifferentiate() const
{
    std::cout << "dy/dx = " << Differentiate() << std::endl;
}