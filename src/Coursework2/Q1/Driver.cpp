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
    std::cout << "Question 1ci" << std::endl;
    std::cout << "f1 approximation:" << std::endl;
    Lagrange* f1approximate0 = new Lagrange(f1, 0.0, 1.0, 10, "data/f1approximate0.dat");
    f1approximate0->Approximate(101);
    std::cout << std::endl << "f2 approximation:" << std::endl;
    Lagrange* f2approximate0 = new Lagrange(f2, 0.0, 1.0, 10, "data/f2approximate0.dat");
    f2approximate0->Approximate(101);
    std::cout << std::endl << "f3 approximation:" << std::endl;
    Lagrange* f3approximate0 = new Lagrange(f3, 0.0, 1.0, 10, "data/f3approximate0.dat");
    f3approximate0->Approximate(101);
    std::cout << std::endl << "f4 approximation:" << std::endl;
    Lagrange* f4approximate0 = new Lagrange(f4, 0.0, 1.0, 10, "data/f4approximate0.dat");
    f4approximate0->Approximate(101);

    delete f1approximate0;
    delete f2approximate0;
    delete f3approximate0;
    delete f4approximate0;

    std::cout << std::endl;


    // ####### PART 2 #######
    std::cout << "Question 1cii" << std::endl;

    std::cout << std::endl << "f1 approximation:" << std::endl;
    std::cout << "n = 1:" << std::endl;
    Lagrange* f1approximate1 = new Lagrange(f1, 0.0, 1.0, 2, "data/f1approximate1.dat");
    f1approximate1->Approximate(101);
    std::cout << "n = 2:" << std::endl;
    Lagrange* f1approximate2 = new Lagrange(f1, 0.0, 1.0, 3, "data/f1approximate2.dat");
    f1approximate2->Approximate(101);
    std::cout << "n = 3:" << std::endl;
    Lagrange* f1approximate3 = new Lagrange(f1, 0.0, 1.0, 4, "data/f1approximate3.dat");
    f1approximate3->Approximate(101);
    std::cout << "n = 15:" << std::endl;
    Lagrange* f1approximate4 = new Lagrange(f1, 0.0, 1.0, 16, "data/f1approximate4.dat");
    f1approximate4->Approximate(101);

    delete f1approximate1;
    delete f1approximate2;
    delete f1approximate3;
    delete f1approximate4;

    std::cout << std::endl << "f2 approximation:" << std::endl;
    std::cout << "n = 1:" << std::endl;
    Lagrange* f2approximate1 = new Lagrange(f2, 0.0, 1.0, 2, "data/f2approximate1.dat");
    f2approximate1->Approximate(101);
    std::cout << "n = 2:" << std::endl;
    Lagrange* f2approximate2 = new Lagrange(f2, 0.0, 1.0, 3, "data/f2approximate2.dat");
    f2approximate2->Approximate(101);
    std::cout << "n = 3:" << std::endl;
    Lagrange* f2approximate3 = new Lagrange(f2, 0.0, 1.0, 4, "data/f2approximate3.dat");
    f2approximate3->Approximate(101);
    std::cout << "n = 7:" << std::endl;
    Lagrange* f2approximate4 = new Lagrange(f2, 0.0, 1.0, 8, "data/f2approximate4.dat");
    f2approximate4->Approximate(101);

    delete f2approximate1;
    delete f2approximate2;
    delete f2approximate3;
    delete f2approximate4;

    std::cout << std::endl << "f3 approximation:" << std::endl;
    std::cout << "n = 2:" << std::endl;
    Lagrange* f3approximate1 = new Lagrange(f3, 0.0, 1.0, 3, "data/f3approximate1.dat");
    f3approximate1->Approximate(101);
    std::cout << "n = 6:" << std::endl;
    Lagrange* f3approximate2 = new Lagrange(f3, 0.0, 1.0, 7, "data/f3approximate2.dat");
    f3approximate2->Approximate(101);
    std::cout << "n = 9:" << std::endl;
    Lagrange* f3approximate3 = new Lagrange(f3, 0.0, 1.0, 10, "data/f3approximate3.dat");
    f3approximate3->Approximate(101);
    std::cout << "n = 15:" << std::endl;
    Lagrange* f3approximate4 = new Lagrange(f3, 0.0, 1.0, 16, "data/f3approximate4.dat");
    f3approximate4->Approximate(101);

    delete f3approximate1;
    delete f3approximate2;
    delete f3approximate3;
    delete f3approximate4;

    std::cout << std::endl << "f4 approximation:" << std::endl;
    std::cout << "n = 1:" << std::endl;
    Lagrange* f4approximate1 = new Lagrange(f4, 0.0, 1.0, 2, "data/f4approximate1.dat");
    f4approximate1->Approximate(101);
    std::cout << "n = 3:" << std::endl;
    Lagrange* f4approximate2 = new Lagrange(f4, 0.0, 1.0, 4, "data/f4approximate2.dat");
    f4approximate2->Approximate(101);
    std::cout << "n = 7:" << std::endl;
    Lagrange* f4approximate3 = new Lagrange(f4, 0.0, 1.0, 8, "data/f4approximate3.dat");
    f4approximate3->Approximate(101);
    std::cout << "n = 15:" << std::endl;
    Lagrange* f4approximate4 = new Lagrange(f4, 0.0, 1.0, 16, "data/f4approximate4.dat");
    f4approximate4->Approximate(101);

    delete f4approximate1;
    delete f4approximate2;
    delete f4approximate3;
    delete f4approximate4;

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