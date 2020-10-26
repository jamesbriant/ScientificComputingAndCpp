#include <iostream>
#include <cmath>

bool repeat()
{

    char answer;
    std::cout << "Would like to ask another question? Y/n: ";
    std::cin >> answer;

    switch(answer){
        case 'Y':
        case 'y':
            return true;
        case 'N':
        case 'n':
            return false;
        default:
            return false;
    }
}

int main(int argc, char* argv[])
{

    int n,m;

    do
    {
        std::cout << "Enter an integer n: " << std::endl;
        std::cin >> n;

        std::cout << "Enter an integer m: " << std::endl;
        std::cin >> m;
        
        int sum = 0;

        for(int i = 1; i<=n; i++)
        {
            sum += pow(i, m);
        }

        std::cout << "The sum is " << sum << std::endl;
    } while(repeat());

    return 0;
}