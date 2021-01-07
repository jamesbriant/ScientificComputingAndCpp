#include "AbstractQuadratureRule.hpp"
#include "Lagrange.hpp"

double AbstractQuadratureRule::CalculateWeightedSum(Vector* pWeights, 
    Vector* pEvaluatedPoints)
{
    double sum = 0.0;

    for(int i = 0; i < length(*pEvaluatedPoints); i++)
    {
        sum += pWeights->Read(i)*pEvaluatedPoints->Read(i);
    }

    return sum;
}

double AbstractQuadratureRule::EvaluateLagrangeBasis(const double xval, 
    const int j, const int npoints, Vector* pPoints) const
{
    Lagrange* p_basis = new Lagrange(mXmin, mXmax, npoints);
    p_basis->SetXPoints(*pPoints);
    
    double output = p_basis->GetL(j, xval);
    delete p_basis;

    return output;
}

