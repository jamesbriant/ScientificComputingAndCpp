#include "Simpson.hpp"

Simpson::Simpson(const double xmin, const double xmax, 
            double (*pFunction)(double))
{
    mXmin = xmin;
    mXmax = xmax;
    mpFunction = pFunction;

    // define the weights and points of the Simpson's Rule
    CalculateXValues();
    CalculateWeights();
}

Simpson::~Simpson()
{
    delete mXvalues;
    delete mWeights;
}

void Simpson::CalculateXValues()
{
    mXvalues = new Vector(3);
    (*mXvalues)[0] = -(mXmax - mXmin)*1.0/2.0 + (mXmax + mXmin)/2.0;
    (*mXvalues)[1] = (mXmax + mXmin)/2.0;
    (*mXvalues)[2] = (mXmax - mXmin)*1.0/2.0 + (mXmax + mXmin)/2.0;
}

void Simpson::CalculateWeights()
{
    mWeights = new Vector(3);
    (*mWeights)[0] = 1.0;
    (*mWeights)[1] = 4.0;
    (*mWeights)[2] = 1.0;
}

double Simpson::ApplyQuadratureRule(Vector* pEvaluatedPoints)
{
    double sum = CalculateWeightedSum(mWeights, pEvaluatedPoints);
    return sum*(mXmax - mXmin)/6.0;
}

double Simpson::IntegrateFunction()
{
    Vector* p_evaluated_points = new Vector(3);
    
    for(int k = 0; k < length(*p_evaluated_points); k++)
    {
        (*p_evaluated_points)[k] = (*mpFunction)(mXvalues->Read(k));
    }

    double output = ApplyQuadratureRule(p_evaluated_points);
    delete p_evaluated_points;

    return output;
}

double Simpson::IntegrateRHSProduct(const int i, int npoints, Vector* pPoints)
{
    Vector* p_evaluated_points = new Vector(3);

    for(int k = 0; k < length(*p_evaluated_points); k++)
    {
        (*p_evaluated_points)[k] = 
            (*mpFunction)(mXvalues->Read(k))*
            EvaluateLagrangeBasis(mXvalues->Read(k), i, npoints, pPoints);
    }

    double output = ApplyQuadratureRule(p_evaluated_points);
    delete p_evaluated_points;

    return output;
}

double Simpson::IntegrateMatrixProduct(const int i, const int j, 
            int npoints, Vector* pPoints)
{
    Vector* p_evaluated_points = new Vector(3);

    for(int k = 0; k < length(*p_evaluated_points); k++)
    {
        (*p_evaluated_points)[k] = 
            EvaluateLagrangeBasis(mXvalues->Read(k), j, npoints, pPoints)*
            EvaluateLagrangeBasis(mXvalues->Read(k), i, npoints, pPoints);
    }

    double output = ApplyQuadratureRule(p_evaluated_points);
    delete p_evaluated_points;

    return output;
}