#ifndef ELLIPSEHEADERDEF
#define ELLIPSEHEADERDEF

class Ellipse
{
    public:
        // Overide the default constructor
        Ellipse();

        // Overide copy constructor
        Ellipse(const Ellipse& aEllipse);

        void SetDimensions(const double width, const double height);
        void SetWidth(const double width);
        void SetHeight(const double height);
        void SetCenter(const double xCenter, const double yCenter);
        
        void GetWidth(double& width) const;
        void GetHeight(double& height) const;
        void GetCenter(double& xCenter, double& yCenter) const;
        void GetArea(double& area) const;
        void GetFoci(double& foci1x, double& foci1y, double& foci2x, double& foci2y) const;
    private:
        double mWidth, mHeight, mXCenter, mYCenter, mArea;
        double CalculateArea();
};

#endif