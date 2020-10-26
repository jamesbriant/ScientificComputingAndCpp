#include <iostream>

int main(int argc, char* argv[])
{
    int i = 9;

    int* p_i;
    p_i = &i;

    *p_i *= 10;
    std::cout << "i = " << *p_i << std::endl;

    int* p_j;
    p_j = new int;

    *p_j = i;
    std::cout << "i = " << *p_j << std::endl;

    delete p_j;

    return 0;
}