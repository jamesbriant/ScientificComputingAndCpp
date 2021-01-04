#include "AbstractQuadratureRule.hpp"
#include "Lagrange.hpp"

// AbstractQuadratureRule::~AbstractQuadratureRule()
// {
//     delete mXvalues;
//     delete mWeights;
// }

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
    const int j, const int npoints, Vector *pPoints) const
{
    Lagrange* Basis = new Lagrange(mpFunction, mXmin, mXmax, npoints);
    Basis->SetXpoints(pPoints);
    
    double output = Basis->GetL(j, xval);
    delete Basis;

    return output;
}

