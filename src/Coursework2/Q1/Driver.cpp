#include <cmath>
#include <iostream>
#include "Lagrange.hpp"

// g++ *.cpp -o Q1.exe

// define function protoypes
double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);

int main(int argc, char* argv[])
{
    // ####### PART 1 #######
    std::cout << "Question 1ci" << std::endl << std::endl;
    std::cout << "f1: ";
    Lagrange* p_f1_approximate0 = 
        new Lagrange(f1, 0.0, 1.0, 10, "data/f1approximate0.dat");
    p_f1_approximate0->Approximate(101);
    std::cout << "f2: ";
    Lagrange* p_f2_approximate0 = 
        new Lagrange(f2, 0.0, 1.0, 10, "data/f2approximate0.dat");
    p_f2_approximate0->Approximate(101);
    std::cout << "f3: ";
    Lagrange* p_f3_approximate0 = 
        new Lagrange(f3, 0.0, 1.0, 10, "data/f3approximate0.dat");
    p_f3_approximate0->Approximate(101);
    std::cout << "f4: ";
    Lagrange* p_f4_approximate0 = 
        new Lagrange(f4, 0.0, 1.0, 10, "data/f4approximate0.dat");
    p_f4_approximate0->Approximate(101);

    delete p_f1_approximate0;
    delete p_f2_approximate0;
    delete p_f3_approximate0;
    delete p_f4_approximate0;

    std::cout << std::endl;


    // ####### PART 2 #######
    std::cout << "Question 1cii" << std::endl << std::endl;

    std::cout << "f1 approximation:" << std::endl;
    std::cout << "n = 1: ";
    Lagrange* p_f1_approximate1 = 
        new Lagrange(f1, 0.0, 1.0, 2, "data/f1approximate1.dat");
    p_f1_approximate1->Approximate(101);
    std::cout << "n = 2: ";
    Lagrange* p_f1_approximate2 = 
        new Lagrange(f1, 0.0, 1.0, 3, "data/f1approximate2.dat");
    p_f1_approximate2->Approximate(101);
    std::cout << "n = 3: ";
    Lagrange* p_f1_approximate3 = 
        new Lagrange(f1, 0.0, 1.0, 4, "data/f1approximate3.dat");
    p_f1_approximate3->Approximate(101);
    std::cout << "n = 15: ";
    Lagrange* p_f1_approximate4 = 
        new Lagrange(f1, 0.0, 1.0, 16, "data/f1approximate4.dat");
    p_f1_approximate4->Approximate(101);

    delete p_f1_approximate1;
    delete p_f1_approximate2;
    delete p_f1_approximate3;
    delete p_f1_approximate4;

    std::cout << std::endl << "f2 approximation:" << std::endl;
    std::cout << "n = 1: ";
    Lagrange* p_f2_approximate1 = 
        new Lagrange(f2, 0.0, 1.0, 2, "data/f2approximate1.dat");
    p_f2_approximate1->Approximate(101);
    std::cout << "n = 2: ";
    Lagrange* p_f2_approximate2 = 
        new Lagrange(f2, 0.0, 1.0, 3, "data/f2approximate2.dat");
    p_f2_approximate2->Approximate(101);
    std::cout << "n = 3: ";
    Lagrange* p_f2_approximate3 = 
        new Lagrange(f2, 0.0, 1.0, 4, "data/f2approximate3.dat");
    p_f2_approximate3->Approximate(101);
    std::cout << "n = 7: ";
    Lagrange* p_f2_approximate4 = 
        new Lagrange(f2, 0.0, 1.0, 8, "data/f2approximate4.dat");
    p_f2_approximate4->Approximate(101);

    delete p_f2_approximate1;
    delete p_f2_approximate2;
    delete p_f2_approximate3;
    delete p_f2_approximate4;

    std::cout << std::endl << "f3 approximation:" << std::endl;
    std::cout << "n = 2: ";
    Lagrange* p_f3_approximate1 = 
        new Lagrange(f3, 0.0, 1.0, 3, "data/f3approximate1.dat");
    p_f3_approximate1->Approximate(101);
    std::cout << "n = 6: ";
    Lagrange* p_f3_approximate2 = 
        new Lagrange(f3, 0.0, 1.0, 7, "data/f3approximate2.dat");
    p_f3_approximate2->Approximate(101);
    std::cout << "n = 9: ";
    Lagrange* p_f3_approximate3 = 
        new Lagrange(f3, 0.0, 1.0, 10, "data/f3approximate3.dat");
    p_f3_approximate3->Approximate(101);
    std::cout << "n = 15: ";
    Lagrange* p_f3_approximate4 = 
        new Lagrange(f3, 0.0, 1.0, 16, "data/f3approximate4.dat");
    p_f3_approximate4->Approximate(101);

    delete p_f3_approximate1;
    delete p_f3_approximate2;
    delete p_f3_approximate3;
    delete p_f3_approximate4;

    std::cout << std::endl << "f4 approximation:" << std::endl;
    std::cout << "n = 1: ";
    Lagrange* p_f4_approximate1 = 
        new Lagrange(f4, 0.0, 1.0, 2, "data/f4approximate1.dat");
    p_f4_approximate1->Approximate(101);
    std::cout << "n = 3: ";
    Lagrange* p_f4_approximate2 = 
        new Lagrange(f4, 0.0, 1.0, 4, "data/f4approximate2.dat");
    p_f4_approximate2->Approximate(101);
    std::cout << "n = 7: ";
    Lagrange* p_f4_approximate3 = 
        new Lagrange(f4, 0.0, 1.0, 8, "data/f4approximate3.dat");
    p_f4_approximate3->Approximate(101);
    std::cout << "n = 15: ";
    Lagrange* p_f4_approximate4 = 
        new Lagrange(f4, 0.0, 1.0, 16, "data/f4approximate4.dat");
    p_f4_approximate4->Approximate(101);

    delete p_f4_approximate1;
    delete p_f4_approximate2;
    delete p_f4_approximate3;
    delete p_f4_approximate4;

    return 0;
}

// Define the functions f1, f2, f3 & f4
double f1(double x)
{
    return pow(x, 3.0);
}

double f2(double x)
{
    return sin(2.0*x);
}

double f3(double x)
{
    return 1.0/(1.0 + 25.0*pow(2.0*x - 1.0, 2.0));
}

double f4(double x)
{
    return sqrt(x);
}