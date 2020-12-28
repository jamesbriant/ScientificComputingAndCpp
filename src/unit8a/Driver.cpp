#include <iostream>
#include "ComplexNumber.hpp"
#include "JuliaSetDrawer.hpp"

// g++ Driver.cpp ComplexNumber.cpp -o julia.exe

ComplexNumber Quadratic(const ComplexNumber z);

int main(int argc, char* argv[])
{

  JuliaSetDrawer drawer(Quadratic, -2.0, 2.0, -2.0, 2.0, 200, 200);

}

ComplexNumber Quadratic(const ComplexNumber z)
{
  ComplexNumber w(1, 0);
  return z.CalculatePower(2.0) + w;
}
