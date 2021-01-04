#ifndef SIMPSONHEADERDEF
#define SIMPSONHEADERDEF

#include "AbstractQuadratureRule.hpp"

class Simpson : public AbstractQuadratureRule
{
    private:
        // hidden default constructor
        Simpson();

    protected:
        void CalculateXValues();
        void CalculateWeights();

        double ApplyQuadratureRule(Vector* pEvaluatedPoints);


    public:
        // specialised constructor
        Simpson(const double xmin, const double xmax, 
            double (*pFunction)(double));
        // overridden default destructor
        ~Simpson();

        double IntegrateFunction();
        double IntegrateRHSProduct(const int i, int npoints, Vector* pPoints);
        double IntegrateMatrixProduct(const int i, const int j, 
            int npoints, Vector* pPoints);
        
};

#endif