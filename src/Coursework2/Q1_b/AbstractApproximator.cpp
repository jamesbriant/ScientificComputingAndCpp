#include "AbstractApproximator.hpp"

// overridden default destructor
AbstractApproximator::~AbstractApproximator()
{
    delete mpXpoints;
    delete mpEvaluatedFunctionPoints;
}

// Calculate the step size in the x-values
double AbstractApproximator::CalculateUniformXStepSize() const
{
    return (mXmax - mXmin)/(double)(mNpoints - 1);
}

// Set uniform points
void AbstractApproximator::CalculateUniformXPoints()
{
    double step_size = CalculateUniformXStepSize();

    for(int i = 0; i < mNpoints; i++)
    {
        (*mpXpoints)[i] = mXmin + i*step_size;
    }
}

// evaluate the function at the x-values
void AbstractApproximator::CalculateFunctionPoints()
{
    for(int i = 0; i < mNpoints; i++)
    {
        (*mpEvaluatedFunctionPoints)[i] = mpFunction(mpXpoints->Read(i));
    }
}

void AbstractApproximator::PrintEvaluatedPoints() const
// This is primarily used for testing
{
    std::cout << *mpEvaluatedFunctionPoints << std::endl;
}

void AbstractApproximator::SetXpoints(Vector *pXpoints)
{
    mpXpoints = pXpoints;
}