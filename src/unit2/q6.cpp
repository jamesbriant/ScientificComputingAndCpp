#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{

    int n;

    std::cout << "Enter an integer n: " << std::endl;
    std::cin >> n;
    
    int sum = 0;

    for(int i = 1; i<=n; i++)
    {
        sum += pow(i, 2);
    }

    std::cout << "The sum is " << sum;

    return 0;
}