#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
    double c, TOL, x0;

    std::cout << "Enter a value for c: ";
    std::cin >> c;

    std::cout << "Enter a tolerance: ";
    std::cin >> TOL;

    std::cout << "Enter an initial estimate for x: ";
    std::cin >> x0;

    double x1, temp;
    int counter = 0;

    do
    {
        x1 = 0.5*(x0 + c/x0);

        temp = x0;
        x0 = x1;
        counter++;
    } while (fabs(x1 - temp) >= TOL);
    
    std::cout << "x=" << x1 << " which took " << counter << " iterations.";

    return 0;
}