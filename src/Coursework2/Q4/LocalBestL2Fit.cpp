#include <cassert>
#include <fstream>
#include "LocalBestL2Fit.hpp"
#include "Lagrange.hpp"

LocalBestL2Fit::LocalBestL2Fit(double (*pFunction)(double), 
            AbstractQuadratureRule* pIntegrator, const double xmin, 
            const double xmax, const int npoints, const int nintervals,
            const std::string outputFileName)
{
    mpFunction = pFunction;
    mpIntegrator = pIntegrator;

    mXmin = xmin;
    mXmax = xmax;

    assert(npoints > 0);
    mNpoints = npoints;
    assert(nintervals > 0);
    mnintervals = nintervals;

    mIntervalWidth = (mXmax - mXmin)/(double)mnintervals;
    mMiniStepSize = mIntervalWidth/(mNpoints - 1);

    mOutputFileName = outputFileName;
    //mIsXPointsSet = false;

    mpPolynomialCoefficients = new Matrix(mnintervals, mNpoints);

    // Calculate 
    Vector* pF = new Vector(mNpoints);
    Vector* pP = new Vector(mNpoints);
    Matrix* pA = new Matrix(mNpoints, mNpoints);
    
    // loop over each sub-interval
    for(int i=0; i< mnintervals; i++)
    {
        CalculateFVector(pF, i);
        CalculateAMatrix(pA, i);
        GaussianElimination(pA, pP, pF);

        for(int j=0; j<mNpoints; j++)
        {
            (*mpPolynomialCoefficients)(i+1, j+1) = pP->Read(j);
        }
    }

    delete pF;
    delete pP;
    delete pA;
}

LocalBestL2Fit::~LocalBestL2Fit()
{
    delete mpPolynomialCoefficients;
}

void LocalBestL2Fit::CalculateFVector(Vector* pF, const int i)
{
    Vector* pLocalXpoints = new Vector(mNpoints);
    for(int k=0; k<mNpoints; k++)
    {
        (*pLocalXpoints)[k] = i*mIntervalWidth + k*mMiniStepSize;
    }

    for(int k = 0; k < mNpoints; k++)
    {
        (*pF)[k] = 
            mpIntegrator->IntegrateRHSProduct(k, mNpoints, pLocalXpoints);
    }

    delete pLocalXpoints;
}

void LocalBestL2Fit::CalculateAMatrix(Matrix* pA, const int i)
{
    Vector* pLocalXpoints = new Vector(mNpoints);
    for(int k=0; k<mNpoints; k++)
    {
        (*pLocalXpoints)[k] = i*mIntervalWidth + k*mMiniStepSize;
    }

    for(int i = 0; i < mNpoints; i++)
    {
        for(int j = 0; j < mNpoints; j++)
        {
            (*pA)(i+1, j+1) =
                mpIntegrator->IntegrateMatrixProduct(i, j, mNpoints, pLocalXpoints);
        }
    }

    delete pLocalXpoints;
}

void LocalBestL2Fit::GaussianElimination(Matrix* p_A, Vector* p_p, Vector* p_f)
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

double LocalBestL2Fit::CalculatePolynomialApproximation(const double x)
{
    // Find the subinterval, k, in which x lies
    int k = (int)(x - mXmin)/mIntervalWidth;
    if(k==mnintervals){k -= 1;} // boundary correction

    double sum = 0.0;
    Lagrange* p_basis = new Lagrange(mXmin + (double)k*mIntervalWidth, 
        mXmin + (double)(k+1)*mIntervalWidth, mNpoints);

    for(int i=0; i<mNpoints; i++)
    {
        sum += (*mpPolynomialCoefficients)(k+1, i+1) * p_basis->GetL(i, x);
    }

    delete p_basis;
    return sum;
}

void LocalBestL2Fit::Approximate(const int nxvalues)
{
    double x;
    double p;
    double h = (mXmax - mXmin)/(double)(nxvalues - 1);

    // create file for saving data
    std::ofstream writeFile(mOutputFileName);

    for(int i = 0; i < nxvalues; i++)
    {
        x = mXmin + i*h;

        // get the approximation pn(x)
        p = CalculatePolynomialApproximation(x);

        // save estimate to file
        writeFile << x << " " << p << "\n";
    }

    writeFile.close();
}