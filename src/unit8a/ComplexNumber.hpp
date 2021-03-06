#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF

class ComplexNumber
{
  public:

    // Overridden default constructor
    ComplexNumber(); 

    // Constructor
    ComplexNumber(const double x, const double y);

    // Calculate Modulus
    double CalculateModulus() const;

    // Calculate Argument
    double CalculateArgument() const;

    // Calculate Power
    ComplexNumber CalculatePower(const double n) const;

    // Overloading binary = operator
    ComplexNumber& operator=(const ComplexNumber& z);

    // Overloading unary - operator
    ComplexNumber operator-() const;

    // Overloading binary + operator
    ComplexNumber operator+(const ComplexNumber& z) const;

    // Overloading binary - operator
    ComplexNumber operator-(const ComplexNumber& z) const;

    // Overridden insertion operator
    friend std::ostream& operator<<(
	                 std::ostream& output, 
	                 const ComplexNumber& z);


  private:

    // Real and imaginary parts
    double mRealPart;
    double mImaginaryPart;

};

#endif
