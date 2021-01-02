#include "AbstractQuadratureRule.hpp"
#include "Lagrange.hpp"

AbstractQuadratureRule::AbstractQuadratureRule(const double xmin, const double xmax, 
            double (*pFunction)(double))
{
    mXmin = xmin;
    mXmax = xmax;
    mpFunction = pFunction;
}

//AbstractQuadratureRule::~AbstractQuadratureRule()
//{
    
//}

double AbstractQuadratureRule::EvaluateLagrangeBasis(const double xval, 
    const int j, const int npoints, const Vector* pPoints) const
{
    Lagrange* Basis = new Lagrange(mpFunction, mXmin, mXmax, );
}

