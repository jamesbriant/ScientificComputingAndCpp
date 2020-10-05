#include <iostream>
#include <cmath>

int main()
{
    std::cout << 19/5 - 1.8 << std::endl; // Incorrect

    std::cout << 17/4.0 - 6.25 << std::endl; // Correct

    std::cout << 56 - 5*(56/5) << std::endl; // Incorrect 

    std::cout << 28/(14/4) << std::endl; // Incorrect

    std::cout << pow(16.0, 1/4) - pow(16, 1.0/4.0) <<  std::endl; // Incorrect

    return 0;
}