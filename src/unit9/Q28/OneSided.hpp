#ifndef ONDESIDEDHEADERDEF
#define ONDESIDEDHEADERDEF

#include "AbstractDifferentiator.hpp"

class OneSided : public AbstractDifferentiator
{
    public:
        // Override the constructor
        OneSided(const double Xval, const double Hval, 
                 double (*pUserFunction)(double));

        double Differentiate() const;
        void PrintDifferentiate() const;
    private:
        // Hide the default constructor
        OneSided();
};

#endif