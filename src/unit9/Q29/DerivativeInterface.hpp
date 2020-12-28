#ifndef DERIVATIVEINTERFACEHEADERDEF
#define DERIVATIVEINTERFACEHEADERDEF

class DerivativeInterface
{
    public:
        virtual double ComputeFunction(const double) const = 0;
        virtual double ComputeDerivative(const double) const = 0;
};

#endif