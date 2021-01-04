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
        double CalculateL(const int j, const double x) const;
        double CalculateP(const double x) const;

    public:
        Lagrange(double (*pFunction)(double), const double xmin, 
            const double xmax, const int npoints, 
            const std::string outputFileName="output.dat");

        // overriden default destructor
        ~Lagrange();

        void PrintPolynomialDenominators() const;
        void Approximate(const int nxvalues);

        // a public accessor to retrieve a lagrange polynomial 
        double GetL(const int j, const double x);
};

#endif