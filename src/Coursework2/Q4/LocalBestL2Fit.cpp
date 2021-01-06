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

    mpXpoints = new Matrix(mnintervals, mNpoints);

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
            (*mpXpoints)(i+1, j+1) = pP->Read(j);
        }
    }

    delete pF;
    delete pP;
    delete pA;

    std::cout << *mpXpoints << std::endl;

    //mpXpoints = new Vector(mNpoints);
    //mpEvaluatedFunctionPoints = new Vector(mNpoints);

    //UseUniformXPoints();

    // // calculates f
    // mpF = new Vector(mNpoints);
    // CalculateFVector(); 

    // // calculates A
    // mpA = new Matrix(mNpoints, mNpoints);
    // CalculateAMatrix();
    
    // // calculates p
    // mpP = new Vector(mNpoints);
    // GaussianElimination(mpA, mpP, mpF);
}

LocalBestL2Fit::~LocalBestL2Fit()
{
    delete mpXpoints;
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
    double sum = 0.0;
    Lagrange* Basis = new Lagrange(mXmin, mXmax, mNpoints);

    // for(int i=0; i<mNpoints; i++)
    // {
    //     sum += mpP->Read(i) * Basis->GetL(i, x);
    // }

    delete Basis;
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
        //true_solution = (*mpFunction)(x);

        // update inf-norm estimate
        // if(fabs(true_solution - p) > inf_norm)
        // {
        //     inf_norm = fabs(true_solution - p);
        // }

        // save estimate to file
        writeFile << x << " " << p << "\n";
    }

    writeFile.close();
}