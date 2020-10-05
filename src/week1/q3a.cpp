#include <iostream>
#include <cmath>

int main()
{
    double celsius;
    std::cout << "Enter a temperature in degrees Celsius: ";
    std::cin >> celsius;

    const double factor = (double)9/(double)5;
    const int translate = 32;

    int fahrenheit = lround(celsius * factor + translate);

    std::cout << "In Fahrenheit, that is: " << fahrenheit << std::endl;

    return 0;
}