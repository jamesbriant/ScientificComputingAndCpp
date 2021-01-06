#ifndef BESTL2FITHEADERDEF
#define BESTL2FITHEADERDEF

#include "AbstractApproximator.hpp"
#include "AbstractQuadratureRule.hpp"
#include "Matrix.hpp"

class BestL2Fit : public AbstractApproximator
{
    private:
        // hidden default constructor
        BestL2Fit();

        AbstractQuadratureRule* mpIntegrator;
        Matrix* mpA;
        Vector* mpF;
        Vector* mpP;

        void CalculateFVector();
        void CalculateAMatrix();
        void GaussianElimination(Matrix* p_A, Vector* p_p, Vector* p_f);

        double CalculatePolynomialApproximation(const double x);
    
    //protected:


    public:
        //specialised constructor
        BestL2Fit(double (*pFunction)(double), 
            AbstractQuadratureRule* pIntegrator, const double xmin, 
            const double xmax, const int npoints, 
            const std::string outputFileName="output.dat");
        
        // overridden default destructor
        ~BestL2Fit();

        void Approximate(const int nxvalues);
};

#endif