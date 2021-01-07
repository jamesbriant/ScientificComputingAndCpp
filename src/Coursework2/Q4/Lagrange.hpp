#ifndef LAGRANGEHEADERDEF
#define LAGRANGEHEADERDEF

#include "AbstractApproximator.hpp"

class Lagrange : public AbstractApproximator
{
    private:
        // Hidden default constructor
        Lagrange();

        // data varaiables
        Vector* mpPolynomialDenominators;

        // vector of f(x) for each x
        Vector* mpEvaluatedFunctionPoints;

        // saves the polynomial denominators to mpEvaluatedFunctionPoints
        void CalculatePolynomialDenominators();

        // evaluates mpFunction at the x values
        void CalculateFunctionPoints();

        double CalculateL(const int j, const double x) const; // Lj(x)
        double CalculatePolynomialApproximation(const double x) const; // p(x)

    public:
        // specialised constructor
        Lagrange(double (*pFunction)(double), const double xmin, 
            const double xmax, const int npoints, 
            const std::string outputFileName="output.dat");

        // specialised constructor for evaluating polynomials
        Lagrange(const double xmin, const double xmax, const int npoints);

        // overriden default destructor
        ~Lagrange();

        // for checking the implementation
        void PrintPolynomialDenominators() const;

        // for checking the implementation
        void PrintEvaluatedPoints() const;

        // saves approximation values
        void Approximate(const int nxvalues);

        // a public accessor to retrieve a lagrange polynomial 
        double GetL(const int j, const double x);
};

#endif