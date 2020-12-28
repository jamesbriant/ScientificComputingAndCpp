#ifndef CUBICPOLYNOMIALHEADERDEF
#define CUBICPOLYNOMIALHEADERDEF

#include "DerivativeInterface.hpp"

class CubicPolynomial : public DerivativeInterface
{
    public:
        double ComputeFunction(const double x) const;
        double ComputeDerivative(const double x) const;
};

#endif