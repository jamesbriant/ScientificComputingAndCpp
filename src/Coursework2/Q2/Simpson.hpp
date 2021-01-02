#ifndef SIMPSONHEADERDEF
#define SIMPSONHEADERDEF

#include "AbstractQuadratureRule.hpp"

class Simpson : public AbstractQuadratureRule
{
    public:
        double IntegrateFunction() = 0;
        double IntegrateRHSProduct(const int i, int npoints, 
            Vector* pPoints) = 0;
        double IntegrateMatrixProduct(const int i, const int j, 
            int npoints, Vector* pPoints) = 0;
        
};

#endif