#include <iostream>
#include "Matrix.hpp"

// g++ Q26.cpp Matrix.cpp -o Q26.exe

int main(int argc, char* argv[])
{
    Matrix A(2.0, -1.0, 0.0, 3.0);
    Matrix B(-0.5, 0.1, 2.3, 1.6);
    Matrix C(-1.0, -1.0, 2.0, 2.0);

    std::cout << "i)" << std::endl;
    std::cout << -A << std::endl;

    std::cout << "ii)" << std::endl;
    std::cout << A + B << std::endl;

    std::cout << "iii)" << std::endl;
    std::cout << B - C*3.0 << std::endl;

    std::cout << "iv)" << std::endl;
    std::cout << B*C << std::endl;

    std::cout << "v)" << std::endl;
    std::cout << B.GetDeterminant() << std::endl;

    std::cout << "vi)" << std::endl;
    std::cout << C.GetInverse() << std::endl;

    return 0;
}