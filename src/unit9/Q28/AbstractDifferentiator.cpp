#include "AbstractDifferentiator.hpp"

void AbstractDifferentiator::SetProperties(const double Xval, const double Hval)
{
    mXval = Xval;
    mHval = Hval;
}

void AbstractDifferentiator::SetFunction(double (*pUserFunction)(double))
{
    mpFunction = pUserFunction;
}