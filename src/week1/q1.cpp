#include <iostream>
#include <string>

int main()
{
    std::string firstname, surname;

    std::cout << "What is your firstname?" << std::endl;
    std::cin >> firstname;
    std::cout << "What is your surname?" << std::endl;
    std::cin >> surname;

    std::cout << "Hello " << firstname << " " << surname;
    std::cout << ", your initials are " << firstname[0] << surname[0] << ".";

    return 0;
}