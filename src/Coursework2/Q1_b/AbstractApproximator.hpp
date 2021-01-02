#ifndef ABSTRACTAPPROXIMATORHEADERDEF
#define ABSTRACTAPPROXIMATORHEADERDEF

#include <string>
#include "Vector.hpp"

class AbstractApproximator
{
    protected:
        // overridden default constructor/destructor
        //AbstractApproximator();
        ~AbstractApproximator();

        // common properties (object data)
        double mXmin;
        double mXmax;
        int mNpoints;
        //double mStepSize; // = (mXmax-mXmin)/(mNpoints-1)
        double (*mpFunction)(double);
        std::string mOutputFileName;

        // vector of x-values, of length mNpoints on [mXmin, mXmax]
        Vector* mpXpoints;
        // vector of f(x) for each x
        Vector* mpEvaluatedFunctionPoints;// = new Vector(mNpoints);

        // calculate stepsize
        double CalculateUniformXStepSize() const;
        void CalculateUniformXPoints();
        // evaluates mpFunction at the x values
        void CalculateFunctionPoints();

    public:
        virtual void Approximate(const int nxvalues) = 0;
        void PrintEvaluatedPoints() const;
        void SetXpoints(Vector *pXpoints);

};

#endif