#include <iostream>
#include "AbstractDifferentiator.hpp"
#include <cmath>

void AbstractDifferentiator::SetProperties(const double Xval, const double Hval)
{
    mXval = Xval;
    mHval = Hval;
}

void AbstractDifferentiator::SetFunction(const DerivativeInterface& pUserFunction)
{
    *mpFunction = pUserFunction;
}

void AbstractDifferentiator::PrintDerivativeError(const double estimate) const
{
std::cout << "Error = " << fabs(mpFunction->ComputeDerivative(mXval) - estimate) << std::endl;
}