#include <iostream>
#include "Matrix.hpp"

// Public Methods
Matrix::Matrix()
{
    ma = 0.0;
    mb = 0.0;
    mc = 0.0;
    md = 0.0;
}

Matrix::Matrix(const double a, const double b,
               const double c, const double d)
{
    ma = a;
    mb = b;
    mc = c;
    md = d;
}

Matrix::Matrix(const Matrix& aMatrix)
{
    ma = aMatrix.Geta();
    mb = aMatrix.Getb();
    mc = aMatrix.Getc();
    md = aMatrix.Getd();
}

double Matrix::GetDeterminant() const
{
    return mb*mc - ma*md;
}

Matrix Matrix::GetInverse() const
{   
    double det = GetDeterminant();
    if(det > 1e-10)
    {
        return Matrix(md/det, -mb/det, -mc/det, ma/det);
    }
    return Matrix();
}

// Overridden insertion operator
std::ostream& operator<<(std::ostream& output,
                         const Matrix& aMatrix)
{
  // Pretty formatting 
  output << aMatrix.ma << ", " << aMatrix.mb << std::endl
         << aMatrix.mc << ", " << aMatrix.md << std::endl;
  return output;
}

Matrix& Matrix::operator=(const Matrix& aMatrix)
{
    ma = aMatrix.Geta();
    mb = aMatrix.Getb();
    mc = aMatrix.Getc();
    md = aMatrix.Getd();
    return *this;
}

Matrix Matrix::operator-() const
{
    return Matrix(-ma, -mb, -mc, -md);
}

Matrix Matrix::operator-(const Matrix& aMatrix) const
{
    return Matrix(ma - aMatrix.Geta(), mb - aMatrix.Getb(),
                  mc - aMatrix.Getc(), md - aMatrix.Getd());
}

Matrix Matrix::operator+(const Matrix& aMatrix) const
{
    return Matrix(ma + aMatrix.Geta(), mb + aMatrix.Getb(),
                  mc + aMatrix.Getc(), md + aMatrix.Getd());
}

Matrix Matrix::operator*(double x) const
{
    return Matrix(x*ma, x*mb,
                  x*mc, x*md);
}

Matrix Matrix::operator*(const Matrix& aMatrix) const
{
    return Matrix(ma*aMatrix.Geta() + mb*aMatrix.Getc(), 
                  ma*aMatrix.Getb() + mb*aMatrix.Getd(),
                  mc*aMatrix.Geta() + md*aMatrix.Getc(), 
                  mc*aMatrix.Getb() + md*aMatrix.Getd());
}

double Matrix::Geta() const
{
    return ma;
}

double Matrix::Getb() const
{
    return mb;
}

double Matrix::Getc() const
{
    return mc;
}

double Matrix::Getd() const
{
    return md;
}
// Private Methods
