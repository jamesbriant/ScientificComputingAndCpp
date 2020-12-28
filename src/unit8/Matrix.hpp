#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF

class Matrix
{
    public:
        // Override the default constructor
        Matrix();
        // Constructor
        Matrix(const double a, const double b,
               const double c, const double d);
        // Copy constructor
        Matrix(const Matrix& aMatrix);

        double Geta() const;
        double Getb() const;
        double Getc() const;
        double Getd() const;

        double GetDeterminant() const;
        Matrix GetInverse() const;

        // Overridden Insertion Operator
        friend std::ostream& operator<<(std::ostream& output, 
                    const Matrix& aMatrix);

        // Overload binary = operator
        Matrix& operator=(const Matrix& aMatrix);

        // Overload - operator
        Matrix operator-() const;
        Matrix operator-(const Matrix& aMatrix) const;

        // Overload + operator
        Matrix operator+(const Matrix& aMatrix) const;

        Matrix operator*(double x) const;
        Matrix operator*(const Matrix& aMatrix) const;

    private:
        double ma, mb, mc, md;
};

#endif