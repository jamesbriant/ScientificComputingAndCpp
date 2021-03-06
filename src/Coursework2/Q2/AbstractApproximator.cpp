#include "AbstractApproximator.hpp"

// Calculate the step size in the x-values
double AbstractApproximator::CalculateUniformXStepSize() const
{
    return (mXmax - mXmin)/(double)(mNpoints - 1);
}

// Set uniform points
void AbstractApproximator::UseUniformXPoints()
{
    double step_size = CalculateUniformXStepSize();

    for(int i = 0; i < mNpoints; i++)
    {
        (*mpXpoints)[i] = mXmin + i*step_size;
    }

    mIsXPointsSet = true;
}

// Set user-defined xPoints
void AbstractApproximator::SetXPoints(Vector* pXPoints)
{
    mpXpoints = pXPoints;
    mIsXPointsSet = true;
}