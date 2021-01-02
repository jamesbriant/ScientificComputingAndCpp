#ifndef GAUSS4POINTHEADERDEF
#define GAUSS4POINTHEADERDEF

#include "AbstractQuadratureRule.hpp"

class Gauss4Points : public AbstractQuadratureRule
{
    public:
        double IntegrateFunction();
        double IntegrateRHSProduct(const int i, int npoints, 
            Vector* pPoints);
        double IntegrateMatrixProduct(const int i, const int j, 
            int npoints, Vector* pPoints);
};

#endif