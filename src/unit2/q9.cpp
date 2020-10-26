#include <iostream>
#include <stdlib.h>
#include <cmath>

int main(int argc, char* argv[])
{
    int n;
    std::cout << "Enter an integer n: ";
    std::cin >> n;

    int counter = 0;
    double x, y;

    for(int i=0; i<=n; i++)
    {
        x = ((double) rand() / (RAND_MAX));
        y = ((double) rand() / (RAND_MAX));

        if(pow(x, 2) + pow(y, 2) < 1.0)
        {
            counter++;
        }
    }

    std::cout << "Estimate for pi is: " << 4.0* (double) counter / (double) n;

    return 0;
}