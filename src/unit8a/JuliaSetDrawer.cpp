#include <iostream>
#include "JuliaSetDrawer.hpp"

// Public Methods
JuliaSetDrawer::JuliaSetDrawer(ComplexNumber (*pFunction)(ComplexNumber), 
                const double minX, const double maxX, 
                const double minY, const double maxY, 
                const int numXPixels, const int numYPixels)
{
    mMinX = minX;
    mMinY = minY;
    mMaxX = maxX;
    mMaxY = maxY;
    mNumXPixels = numXPixels;
    mNumYPixels = numYPixels;
    mpFunction = pFunction;
}


// Private Methods

int JuliaSetDrawer::IterateMap(const ComplexNumber& z0)
{
    int greyScale = 255;
    ComplexNumber z = z0;

    while (z.CalculateModulus() < 10.0 && greyScale > 0)
    {
        z = (*mpFunction)(z);

        greyScale -= 5;
    };

    return greyScale;
}