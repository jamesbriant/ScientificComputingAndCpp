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

    // Overridden insertion operator
    friend std::ostream& operator<<(
	                 std::ostream& output, 
	                 const ComplexNumber& z);

    ComplexNumber operator-() const;
    ComplexNumber operator-(const ComplexNumber& z) const;
    ComplexNumber operator+(const ComplexNumber& z) const;


  private:

    // Real and imaginary parts
    double mRealPart;
    double mImaginaryPart;

};

#endif
