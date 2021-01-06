#ifndef ABSTRACTAPPROXIMATORHEADERDEF
#define ABSTRACTAPPROXIMATORHEADERDEF

#include <string>
#include "Vector.hpp"

class AbstractApproximator
{
    protected:
        // common properties (object data)
        double mXmin;
        double mXmax;
        int mNpoints;
        double (*mpFunction)(double);
        std::string mOutputFileName;
        bool mIsXPointsSet;

        // vector of x-values, of length mNpoints on [mXmin, mXmax]
        Vector* mpXpoints;

        // calculate uniform stepsize
        double CalculateUniformXStepSize() const;

    public:
        // saves approximations to a file
        virtual void Approximate(const int nxvalues) = 0;

        // sets the X points to be uniformly spaced
        void UseUniformXPoints();

        // use user defined Xpoints
        void SetXPoints(Vector* pXPoints);
};

#endif