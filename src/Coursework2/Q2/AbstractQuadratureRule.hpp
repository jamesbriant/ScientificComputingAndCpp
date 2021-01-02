#ifndef ABSTRACTQUADRATURERULEHEADERDEF
#define ABSTRACTQUADRATURERULEHEADERDEF

#include "Vector.hpp"

class AbstractQuadratureRule
{
    private:
        // hidden default constructor
        AbstractQuadratureRule();

    protected:
        // specialised constructor
        AbstractQuadratureRule(const double xmin, const double xmax, 
            double (*pFunction)(double));

        double mXmin;
        double mXmax;
        double (*mpFunction)(double);

        double EvaluateLagrangeBasis(const double xval, const int j, 
            const int npoints, const Vector* pPoints) const;
    
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