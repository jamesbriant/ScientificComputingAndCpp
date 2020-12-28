#include <cmath>
#include "CubicPolynomial.hpp"

double CubicPolynomial::ComputeFunction(const double x) const
{
    return pow(x, 3.0);
}

double CubicPolynomial::ComputeDerivative(const double x) const
{
    return 3.0 * pow(x, 2.0);
}