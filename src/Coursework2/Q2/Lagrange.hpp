#ifndef LAGRANGEHEADERDEF
#define LAGRANGEHEADERDEF

#include "AbstractApproximator.hpp"

class Lagrange : public AbstractApproximator
{
    private:
        // Hide the default constructor
        Lagrange();

        // data varaiables
        Vector* mpPolynomialDenominators;

        void CalculatePolynomialDenominators();
        double CalculateP(const double x) const;

    public:
        Lagrange(double (*pFunction)(double), const double xmin, 
            const double xmax, const int npoints, 
            const std::string outputFileName="output.dat");

        // overriden default destructor
        ~Lagrange();

        void PrintPolynomialDenominators() const;
        void Approximate(const int nxvalues);
        
        // This method has moved from private in Q1 to public in Q2
        double CalculateL(const int j, const double x) const;
};

#endif