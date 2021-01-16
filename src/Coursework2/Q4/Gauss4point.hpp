#ifndef GAUSS4POINTHEADERDEF
#define GAUSS4POINTHEADERDEF

#include "AbstractQuadratureRule.hpp"

class Gauss4Point : public AbstractQuadratureRule
{
    private:
        // hidden default constructor
        Gauss4Point();

    protected:
        void CalculateXValues(int intervalK = 0, int nintervals = 1);
        void CalculateWeights();

        double ApplyQuadratureRule(Vector* pEvaluatedPoints);


    public:
        // specialised constructor
        Gauss4Point(const double xmin, const double xmax, 
            double (*pFunction)(double));
        
        // overridden default destructor
        ~Gauss4Point();

        void SetIntervals(int intervalK = 0, int nintervals = 1);

        double IntegrateFunction();
        double IntegrateRHSProduct(const int i, int npoints, Vector* pPoints);
        double IntegrateMatrixProduct(const int i, const int j, 
            int npoints, Vector* pPoints);
        
};

#endif