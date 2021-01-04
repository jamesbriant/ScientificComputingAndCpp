#ifndef ABSTRACTQUADRATURERULEHEADERDEF
#define ABSTRACTQUADRATURERULEHEADERDEF

#include "Vector.hpp"

class AbstractQuadratureRule
{
    protected:
        // class properties
        double mXmin;
        double mXmax;
        double (*mpFunction)(double);
        Vector* mXvalues;
        Vector* mWeights;

        // each quadrature has different weights and Xvalues
        virtual void CalculateXValues() = 0;
        virtual void CalculateWeights() = 0;

        // an implementation of the quadrature rule
        virtual double ApplyQuadratureRule(Vector* pEvaluatedPoints) = 0;
        double CalculateWeightedSum(Vector* pWeights, Vector* pEvaluatedPoints);

        double EvaluateLagrangeBasis(const double xval, const int j, 
            const int npoints, Vector* pPoints) const;
    
    public:
        // overridden default destructor
        //~AbstractQuadratureRule();

        virtual double IntegrateFunction() = 0;
        virtual double IntegrateRHSProduct(const int i, int npoints, 
            Vector* pPoints) = 0;
        virtual double IntegrateMatrixProduct(const int i, const int j, 
            int npoints, Vector* pPoints) = 0;
};

#endif