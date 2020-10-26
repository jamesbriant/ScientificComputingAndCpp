#include <iostream>
#include <cmath>

int main()
{
    double a, b, c;

    std::cout << "a = ";
    std::cin >> a;

    std::cout << "b = ";
    std::cin >> b;

    std::cout << "c = ";
    std::cin >> c;

    if(a == 0)
    {
        std::cout << "This is linear, not quadratic." << std::endl;
        std::cout << "The root is at " << -c/b << ".";

        return 0;
    }

    double discriminant = pow(b,2) - 4*a*c;

    if(discriminant < 0)
    {
        std::cout << "No real roots exist.";
    }
    else if(discriminant == 0)
    {
        std::cout << "There is only 1 root at " << -b/(2*a);
    }
    else
    {
        std::cout << "The first root is at ";
        std::cout << (-b - sqrt(discriminant))/(2*a) << std::endl;
        std::cout << "The second root is at ";
        std::cout << (-b + sqrt(discriminant))/(2*a) << std::endl;
    }

    return 0;
}