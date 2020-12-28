#ifndef CENTREDHEADERDEF
#define CENTREDHEADERDEF

#include "AbstractDifferentiator.hpp"

class Centred : public AbstractDifferentiator
{
    public:
        // Override the constructor
        Centred(const double Xval, const double Hval, 
                 double (*pUserFunction)(double));

        double Differentiate() const;
        void PrintDifferentiate() const;
    private:
        // Hide the default constructor
        Centred();
};

#endif