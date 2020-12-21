#include <iostream>
#include "Ellipse.hpp"

// g++ Q24.cpp Ellipse.cpp -o Q24.exe

int main()
{
    Ellipse a_Ellipse1;
    Ellipse* p_Ellipse2 = new Ellipse();

    double area1;
    a_Ellipse1.GetArea(area1);
    std::cout << area1 << std::endl;

    delete p_Ellipse2;

    return 0;
}