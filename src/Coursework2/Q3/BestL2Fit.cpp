#include <cassert>
#include <fstream>
#include "BestL2Fit.hpp"
#include "Lagrange.hpp"

BestL2Fit::BestL2Fit(double (*pFunction)(double), 
            AbstractQuadratureRule* pIntegrator, const double xmin, 
            const double xmax, const int npoints, 
            const std::string outputFileName)
{
    mpFunction = pFunction;
    mpIntegrator = pIntegrator;
    mXmin = xmin;
    mXmax = xmax;
    assert(npoints > 0);
    mNpoints = npoints;
    mOutputFileName = outputFileName;
    mIsXPointsSet = false;

    mpXpoints = new Vector(mNpoints);
    //mpEvaluatedFunctionPoints = new Vector(mNpoints);

    UseUniformXPoints();

    // calculates f
    mpF = new Vector(mNpoints);
    CalculateFVector(); 

    // calculates A
    mpA = new Matrix(mNpoints, mNpoints);
    CalculateAMatrix();
    
    // calculates p
    mpP = new Vector(mNpoints);
    GaussianElimination(mpA, mpP, mpF);
}

BestL2Fit::~BestL2Fit()
{
    delete mpA;
    delete mpP;
    delete mpF;
}

void BestL2Fit::CalculateFVector()
{
    for(int k = 0; k < mNpoints; k++)
    {
        (*mpF)[k] = 
            mpIntegrator->IntegrateRHSProduct(k, mNpoints, mpXpoints);
    }

}

void BestL2Fit::CalculateAMatrix()
{
    for(int i = 0; i < mNpoints; i++)
    {
        for(int j = 0; j < mNpoints; j++)
        {
            (*mpA)(i+1, j+1) =
                mpIntegrator->IntegrateMatrixProduct(i, j, mNpoints, mpXpoints);
        }
    }
}

void BestL2Fit::GaussianElimination(Matrix* p_A, Vector* p_p, Vector* p_f)
{
    int systemSize = p_p->GetSize();

    // Forward elimination step
    for (int i=1; i<systemSize; i++)
    {
        // Elimination
        double diagonal = 1.0 / (*p_A)(i,i);
        for (int j=i+1; j<=systemSize; j++)
        {
            double multiplier = diagonal * (*p_A)(j,i);
            for (int k=i; k<=systemSize; k++)
            {
                (*p_A)(j,k) = (*p_A)(j,k) - multiplier * (*p_A)(i,k);
            }
            (*p_f)(j) = (*p_f)(j) - multiplier * (*p_f)(i);
        }
    }

  // Backward substitution step
    (*p_p)(systemSize) = (*p_f)(systemSize) / (*p_A)(systemSize,systemSize);
    for (int i=systemSize-1; i>=1; i--)
    {
        (*p_p)(i) = (*p_f)(i);
        for (int k=i+1; k<=systemSize; k++)
        {
            (*p_p)(i) = (*p_p)(i) - (*p_A)(i,k) * (*p_p)(k);
        }
        (*p_p)(i) = (*p_p)(i) / (*p_A)(i,i);
    }
}

double BestL2Fit::CalculatePolynomialApproximation(const double x)
{
    double sum = 0.0;
    Lagrange* p_basis = new Lagrange(mXmin, mXmax, mNpoints);

    for(int i=0; i<mNpoints; i++)
    {
        sum += mpP->Read(i) * p_basis->GetL(i, x);
    }

    delete p_basis;
    return sum;
}

void BestL2Fit::Approximate(const int nxvalues)
{
    double x;
    double p;
    double step_size = (mXmax - mXmin)/(double)(nxvalues - 1);

    // create file for saving data
    std::ofstream writeFile(mOutputFileName);

    for(int i = 0; i < nxvalues; i++)
    {
        x = mXmin + i*step_size;

        // get the approximation pn(x)
        p = CalculatePolynomialApproximation(x);

        // save estimate to file
        writeFile << x << " " << p << "\n";
    }

    writeFile.close();
}