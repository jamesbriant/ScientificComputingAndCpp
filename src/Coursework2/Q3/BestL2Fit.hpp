#ifndef BESTL2FITHEADERDEF
#define BESTL2FITHEADERDEF

#include "AbstractApproximator.hpp"
#include "AbstractQuadratureRule.hpp"

class BestL2Fit : public AbstractApproximator
{
    private:
        BestL2Fit();
    
    //protected:


    public:
        //specialised constructor
        BestL2Fit(double (*pFunction)(double), 
            AbstractQuadratureRule* pIntegrator, const double xmin, 
            const double xmax, const int npoints, 
            const std::string outputFileName="output.dat");
        void Approximate(const int nxvalues);
};

#endif