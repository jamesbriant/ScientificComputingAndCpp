#include "AbstractApproximator.hpp"

// overridden default destructor
AbstractApproximator::~AbstractApproximator()
{
    delete mpEvaluatedFunctionPoints;
}

// Calculate the step size in the x-values
void AbstractApproximator::CalculateStepSize()
{
    mStepSize = (mXmax - mXmin)/(double)(mNpoints - 1);
}

// evaluate the function at the x-values
void AbstractApproximator::CalculateFunctionPoints()
{
    for(int i = 0; i < mNpoints; i++)
    {
        (*mpEvaluatedFunctionPoints)[i] = mpFunction(mXmin + i*mStepSize);
    }
}

void AbstractApproximator::PrintEvaluatedPoints() const
// This is primarily used for testing
{
    std::cout << *mpEvaluatedFunctionPoints << std::endl;
}