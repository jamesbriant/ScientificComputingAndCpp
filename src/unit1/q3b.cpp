#include <iostream>
#include <string>
#include <cmath>

int getStringLength(std::string input)
{
    return input.length() / 8;
}

int getTemperature(std::string input)
{
    std::string output = input.substr(0, getStringLength(input) - 1);
    return stoi(output);
}

bool checkForUnit(std::string input)
{
    char unit = input.back();
    if(unit != 'c' && unit != 'C' && unit != 'f' && unit != 'F')
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    std::string input;
    do
    {
        std::cout << "Enter a temperature including the unit: ";
        std::cin >> input;
    } while (!checkForUnit(input));
    
    const double factor = (double)9/(double)5;
    const int translate = 32;

    int temperature = getTemperature(input);
    char unit = input.back();

    if(unit == 'F' || unit == 'f')
    {
        int output = lround(temperature - translate)/factor;
        std::cout << "That is " << output << " degrees C.";
    }
    else
    {
        int output = lround(temperature * factor + translate);
        std::cout << "That is " << output << " degrees F.";
    }

    return 0;
}