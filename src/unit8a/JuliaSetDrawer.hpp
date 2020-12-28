#ifndef JULIASETDRAWERHEADERDEF
#define JULIASETDRAWERHEADERDEF

#include "ComplexNumber.hpp"

class JuliaSetDrawer
{
    public:
        JuliaSetDrawer(ComplexNumber (*pFunction)(ComplexNumber), 
                const double minX, const double maxX, 
                const double minY, const double maxY, 
                const int numXPixels, const int numYPixels);

    private:
        double mMinX, mMinY, mMaxX, mMaxY;
        int mNumXPixels, mNumYPixels;
        
        // Hidden default Constructor
        JuliaSetDrawer();

        ComplexNumber (*mpFunction)(ComplexNumber);

        int IterateMap(const ComplexNumber& z0);
};



#endif