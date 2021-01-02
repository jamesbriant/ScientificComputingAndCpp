#include <cmath>
#include <cassert>
#include <fstream>
#include "Lagrange.hpp"

Lagrange::Lagrange(double (*pFunction)(double), const double xmin, 
            const double xmax, const int npoints, 
            const std::string outputFileName)
{
    mpFunction = pFunction;
    mXmin = xmin;
    mXmax = xmax;
    assert(npoints > 0);
    mNpoints = npoints;
    mOutputFileName = outputFileName;

    mpEvaluatedFunctionPoints = new Vector(mNpoints);
    mpPolynomialDenominators = new Vector(mNpoints);

    CalculateStepSize();
    CalculateFunctionPoints();
    CalculatePolynomialDenominators();
}

Lagrange::~Lagrange()
{
    delete mpPolynomialDenominators;
}

void Lagrange::CalculatePolynomialDenominators()
{
    double product = pow(mStepSize, mNpoints-1); // = h^n
    double denominator;

    // iterate over each x-value
    for(int j = 0; j < mNpoints; j++)
    {
        denominator = product;

        // iterate over each xj, xk pair
        for(int k = 0; k < mNpoints; k++)
        {
            if(j != k)
            {
                denominator *= j-k;
            }
        }

        // set the denominator
        (*mpPolynomialDenominators)[j] = denominator;
    }
}

void Lagrange::PrintPolynomialDenominators() const
// This is primarily used for testing
{
    std::cout << *mpPolynomialDenominators << std::endl;
}

double Lagrange::CalculateL(const int j, const double x) const
// returns the jth lagrange polynomial evaluated at x
{
    double product = 1.0;

    for(int k = 0; k < mNpoints; k++)
    {
        if(k != j)
        {
            product *= x - mXmin - k*mStepSize;
        }
    }

    return product/(*mpPolynomialDenominators)[j];
}

double Lagrange::CalculateP(const double x) const
{
    double p = 0.0;

    for(int j = 0; j < mNpoints; j++)
    {
        p += (*mpEvaluatedFunctionPoints)[j] * CalculateL(j, x);
    }

    return p;
}

void Lagrange::Approximate(const int nxvalues)
{
    double h = (mXmax - mXmin)/(double)(nxvalues - 1);
    double x;
    double p;
    double true_solution;
    double inf_norm = 0.0;

    // create file for saving data
    std::ofstream writeFile(mOutputFileName);

    // interpolate the solution for each of the nxvalues
    for(int i = 0; i < nxvalues; i++)
    {
        x = mXmin + i*h;

        // get the approximation pn(x)
        p = CalculateP(x);
        true_solution = (*mpFunction)(x);

        //std::cout << "p = " << p << ", sol = " << true_solution << std::endl;

        // update inf-norm estimate
        if(fabs(true_solution - p) > inf_norm)
        {
            inf_norm = fabs(true_solution - p);
        }

        // save estimate to file
        writeFile << x << " " << p << "\n";
    }

    writeFile.close();
    std::cout << "inf-norm approximation = " << inf_norm << std::endl;
}