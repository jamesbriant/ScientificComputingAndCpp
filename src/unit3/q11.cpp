#include <iostream>

int main(int argc, char* argv[])
{
    double a, b, c, d;
    std::cout << "Enter the values for a, b, c & d. eg 1 3 2 4" << std::endl;
    std::cin >> a >> b >> c >> d;

    double determinant = a*d - b*c;

    double a1, b1, c1, d1;
    a1 = d/determinant;
    b1 = -b/determinant;
    c1 = -c/determinant;
    d1 = a/determinant;

    std::cout << a*a1 + b*c1 << std::endl;
    std::cout << a*b1 + b*d1 << std::endl;
    std::cout << c*a1 + d*c1 << std::endl;
    std::cout << c*b1 + d*d1 << std::endl;

    return 0;
}