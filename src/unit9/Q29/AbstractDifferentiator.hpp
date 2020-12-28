#ifndef ABSTRACTDIFFERENTIATORHEADERDEF
#define ABSTRACTDIFFERENTIATORHEADERDEF

#include "DerivativeInterface.hpp"

class AbstractDifferentiator
{
    public:
        virtual double Differentiate() const = 0;

        void SetProperties(const double Xval, const double Hval);
        //void SetFunction(double (*pUserFunction)(double));
        void SetFunction(const DerivativeInterface& pUserFunction);
        
        void PrintDerivativeError(const double estimate) const;

    protected:
        double mXval, mHval;
        //double (*mpFunction)(double);
        DerivativeInterface* mpFunction;
};

#endif