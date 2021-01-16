#include "AbstractQuadratureRule.hpp"
#include "Lagrange.hpp"

// returns the sum of pEvaluatedPoints using the pWeights as weights
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

// evaluate jth lagrange basis at xval
double AbstractQuadratureRule::EvaluateLagrangeBasis(const double xval, 
    const int j, const int npoints, Vector* pPoints) const
{
    // set-up the lagrange functions
    Lagrange* p_basis = new Lagrange(mXmin, mXmax, npoints);
    // user defined Xpoints
    p_basis->SetXPoints(*pPoints);
    
    // evaluate the jth lagrange function at xval
    double output = p_basis->GetL(j, xval);
    delete p_basis;

    return output;
}

