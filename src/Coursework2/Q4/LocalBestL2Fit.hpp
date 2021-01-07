#ifndef BESTL2FITHEADERDEF
#define BESTL2FITHEADERDEF

#include "AbstractApproximator.hpp"
#include "AbstractQuadratureRule.hpp"
#include "Matrix.hpp"

class LocalBestL2Fit : public AbstractApproximator
{
    private:
        // hidden default constructor
        LocalBestL2Fit();

        int mnintervals;
        double mIntervalWidth;
        double mMiniStepSize;
        AbstractQuadratureRule* mpIntegrator;
        Matrix* mpPolynomialCoefficients;

        void CalculateFVector(Vector* pF, const int i);
        void CalculateAMatrix(Matrix* pA, const int i);
        void GaussianElimination(Matrix* p_A, Vector* p_p, Vector* p_f);

        double CalculatePolynomialApproximation(const double x);
    
    //protected:


    public:
        //specialised constructor
        LocalBestL2Fit(double (*pFunction)(double), 
            AbstractQuadratureRule* pIntegrator, const double xmin, 
            const double xmax, const int npoints, const int nintervals,
            const std::string outputFileName="output.dat");
        
        // overridden default destructor
        ~LocalBestL2Fit();

        void Approximate(const int nxvalues);
};

#endif