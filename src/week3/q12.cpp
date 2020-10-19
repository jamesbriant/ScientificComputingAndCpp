#include <iostream>

int main(int argc, char* argv[])
{
    int i = 9;

    int* p_i;
    p_i = &i;

    std::cout << *p_i * 10;

    int* p_j;
    p_j = new int;

    p_j = p_i;

    delete p_j;

    return 0;
}