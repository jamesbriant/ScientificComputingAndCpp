#ifndef ABSTRACTDIFFERENTIATORHEADERDEF
#define ABSTRACTDIFFERENTIATORHEADERDEF

class AbstractDifferentiator
{
    public:
        virtual double Differentiate() const = 0;

        void SetProperties(const double Xval, const double Hval);
        void SetFunction(double (*pUserFunction)(double));

    protected:
        double mXval, mHval;
        double (*mpFunction)(double);
};

#endif