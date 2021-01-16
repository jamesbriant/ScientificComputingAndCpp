#include <cmath>
#include "Gauss4Point.hpp"

Gauss4Point::Gauss4Point(const double xmin, const double xmax, 
            double (*pFunction)(double))
{
    mXmin = xmin;
    mXmax = xmax;
    mpFunction = pFunction;

    // define the weights and points of the Gauss4Point Rule
    CalculateXValues();
    CalculateWeights();
}

Gauss4Point::~Gauss4Point()
{
    delete mXvalues;
    delete mWeights;
}

// set the gauss-4-point xvalues
void Gauss4Point::CalculateXValues()
{
    mXvalues = new Vector(4);
    double a = sqrt(3.0/7.0 + 2.0/7.0*sqrt(6.0/5.0));
    double b = sqrt(3.0/7.0 - 2.0/7.0*sqrt(6.0/5.0));

    (*mXvalues)[0] = -(mXmax - mXmin)*a/2.0 + (mXmax + mXmin)/2.0;
    (*mXvalues)[1] = -(mXmax - mXmin)*b/2.0 + (mXmax + mXmin)/2.0;
    (*mXvalues)[2] = (mXmax - mXmin)*b/2.0 + (mXmax + mXmin)/2.0;
    (*mXvalues)[3] = (mXmax - mXmin)*a/2.0 + (mXmax + mXmin)/2.0;
}

// set the gauss-4-point weights
void Gauss4Point::CalculateWeights()
{
    mWeights = new Vector(4);
    (*mWeights)[0] = (18.0 - sqrt(30.0))/36.0;
    (*mWeights)[1] = (18.0 + sqrt(30.0))/36.0;
    (*mWeights)[2] = mWeights->Read(1);
    (*mWeights)[3] = mWeights->Read(0);
}

// implementation of Gauss-4-point rule
double Gauss4Point::ApplyQuadratureRule(Vector* pEvaluatedPoints)
{
    double sum = CalculateWeightedSum(mWeights, pEvaluatedPoints);
    return sum*(mXmax - mXmin)/2.0;
}

// returns Gauss-4-point approximation of integral of mpFunction
double Gauss4Point::IntegrateFunction()
{
    Vector* p_evaluated_points = new Vector(4);

    // evauate the function at each X point
    for(int k = 0; k < length(*p_evaluated_points); k++)
    {
        (*p_evaluated_points)[k] = (*mpFunction)(mXvalues->Read(k));
    }

    double output = ApplyQuadratureRule(p_evaluated_points);
    delete p_evaluated_points;

    return output;
}

// returns Gauss-4-point approximation of integral of mpFunction*L
double Gauss4Point::IntegrateRHSProduct(const int i, int npoints, Vector* pPoints)
{
    Vector* p_evaluated_points = new Vector(4);

    // evauate the function at each X point
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

// returns Gauss-4-point approximation of integral of Li*Lj
double Gauss4Point::IntegrateMatrixProduct(const int i, const int j, 
            int npoints, Vector* pPoints)
{
    Vector* p_evaluated_points = new Vector(4);

    // evauate the function at each X point
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