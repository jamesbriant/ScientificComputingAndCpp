#include <cmath>
#include <cassert>
#include "Ellipse.hpp"

// PUBLIC METHODS -------------------------------------------------------
// Overide default constructor
Ellipse::Ellipse()
{
    mWidth = 2.0;
    mHeight = 2.0;
    mXCenter = 0.0;
    mYCenter = 0.0;
    mArea = CalculateArea();
}

// Overide default copy constructor
Ellipse::Ellipse(const Ellipse& aEllipse)
{
    aEllipse.GetWidth(mWidth);
    aEllipse.GetHeight(mHeight);
    aEllipse.GetCenter(mXCenter, mYCenter);
    aEllipse.GetArea(mArea);
}

void Ellipse::SetDimensions(const double width, const double height)
{
    SetWidth(width);
    SetHeight(height);
    mArea = CalculateArea();
}

void Ellipse::SetWidth(const double width)
{
    assert(width > 0);
    mWidth = width;
}

void Ellipse::SetHeight(const double height)
{
    assert(height > 0);
    mHeight = height;
}

void Ellipse::SetCenter(const double xCenter, const double yCenter)
{
    mXCenter = xCenter;
    mYCenter = yCenter;
}

void Ellipse::GetWidth(double& width) const
{
    width = mWidth;
}

void Ellipse::GetHeight(double& height) const
{
    height = mHeight;
}

void Ellipse::GetCenter(double& xCenter, double& yCenter) const
{
    xCenter = mXCenter;
    yCenter = mYCenter;
}

void Ellipse::GetArea(double& area) const
{
    area = mArea;
}

void Ellipse::GetFoci(double& foci1x, double& foci1y, double& foci2x, double& foci2y) const
{
    if(mWidth > mHeight)
    {
        foci1y = mYCenter;
        foci2y = mYCenter;

        double c = sqrt(pow(mWidth/2, 2) - pow(mHeight/2, 2));

        foci1x = mXCenter - c;
        foci2x = mXCenter + c;
    }
    else
    {
        foci1x = mXCenter;
        foci2x = mXCenter;

        double c = sqrt(pow(mHeight/2, 2) - pow(mWidth/2, 2));
        
        foci1y = mYCenter - c;
        foci2y = mYCenter + c;
    }
}

// PRIVATE METHODS ---------------------------------------------------------

double Ellipse::CalculateArea()
{
    return M_PI * mWidth/2 * mHeight/2;
}

