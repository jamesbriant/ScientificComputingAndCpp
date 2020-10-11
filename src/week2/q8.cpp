#include <iostream>

int fibonacci(int n)
{
    switch(n)
    {
        case 0:
        case 1:
            return 1;
        default:
            return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(int argc, char* argv[])
{
    int n;
    std::cout << "Enter an integer n: ";
    std::cin >> n;

    for(int i=0; fibonacci(i) <= n; i++)
    {
        std::cout << fibonacci(i) << std::endl;
    }

    return 0;
}