#include <cmath>
#include "Simpson.hpp"
#include "Gauss4point.hpp"
#include "Matrix.hpp"
//#include "GaussianElimination.cpp"

// g++ *.cpp -o Q2.exe

// define function protoypes
double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);
void GaussianElimination(Matrix* p_A, Vector* p_p, Vector* p_f);

int main(int argc, char* argv[])
{
    std::cout << "Question 2ci - f integral approximations" << std::endl;

    std::cout << std::endl << "Simpson's Rule:" << std::endl;
    Simpson* p_simpson_f1 = new Simpson(0.0, 1.0, f1);
    std::cout << "f1: " << p_simpson_f1->IntegrateFunction() << std::endl;
    Simpson* p_simpson_f2 = new Simpson(0.0, 1.0, f2);
    std::cout << "f2: " << p_simpson_f2->IntegrateFunction() << std::endl;
    Simpson* p_simpson_f3 = new Simpson(0.0, 1.0, f3);
    std::cout << "f3: " << p_simpson_f3->IntegrateFunction() << std::endl;
    Simpson* p_simpson_f4 = new Simpson(0.0, 1.0, f4);
    std::cout << "f4: " << p_simpson_f4->IntegrateFunction() << std::endl;
    //delete p_simpson_f1;
    delete p_simpson_f2;
    delete p_simpson_f3;
    delete p_simpson_f4;

    std::cout << "Gauss-4-Point Rule:" << std::endl;
    Gauss4Point* p_gauss_f1 = new Gauss4Point(0.0, 1.0, f1);
    std::cout << "f1: " << p_gauss_f1->IntegrateFunction() << std::endl;
    Gauss4Point* p_gauss_f2 = new Gauss4Point(0.0, 1.0, f2);
    std::cout << "f2: " << p_gauss_f2->IntegrateFunction() << std::endl;
    Gauss4Point* p_gauss_f3 = new Gauss4Point(0.0, 1.0, f3);
    std::cout << "f3: " << p_gauss_f3->IntegrateFunction() << std::endl;
    Gauss4Point* p_gauss_f4 = new Gauss4Point(0.0, 1.0, f4);
    std::cout << "f4: " << p_gauss_f4->IntegrateFunction() << std::endl;
    //delete p_gauss_f1;
    delete p_gauss_f2;
    delete p_gauss_f3;
    delete p_gauss_f4;



    std::cout << std::endl << "Question 2cii - f*L integral approximations" 
        << std::endl;

    Vector* p_linear = new Vector(2);
    (*p_linear)[0] = 0.0;
    (*p_linear)[1] = 1.0;

    Vector* p_quadratic = new Vector(3);
    (*p_quadratic)[0] = 0.0;
    (*p_quadratic)[1] = 0.5;
    (*p_quadratic)[2] = 1.0;

    Vector* p_simpson_linear_f = new Vector(2);
    Vector* p_simpson_quadratic_f = new Vector(3);
    Vector* p_gauss_linear_f = new Vector(2);
    Vector* p_gauss_quadratic_f = new Vector(3);

    for(int k = 0; k < 2; k++)
    {
        (*p_simpson_linear_f)[k] = 
            p_simpson_f1->IntegrateRHSProduct(k, 2, p_linear);
        (*p_gauss_linear_f)[k] = 
            p_gauss_f1->IntegrateRHSProduct(k, 2, p_linear);

    }
    for(int k = 0; k < 3; k++)
    {
        (*p_simpson_quadratic_f)[k] = 
            p_simpson_f1->IntegrateRHSProduct(k, 3, p_quadratic);
        (*p_gauss_quadratic_f)[k] = 
            p_gauss_f1->IntegrateRHSProduct(k, 3, p_quadratic);

    }

    std::cout << std::endl << "Simpson's Rule" << std::endl;
    std::cout << "Linear:" << std::endl;
    std::cout << *p_simpson_linear_f;

    std::cout << "Quadratic:" << std::endl;
    std::cout << *p_simpson_quadratic_f;

    std::cout << std::endl << "Gauss-4-Point Rule" << std::endl;
    std::cout << "Linear:" << std::endl;
    std::cout << *p_gauss_linear_f;

    std::cout << "Quadratic:" << std::endl;
    std::cout << *p_gauss_quadratic_f;



    std::cout << std::endl << "Question 2ciii - Li*Lj integral approximations" 
        << std::endl;

    Matrix* p_simpson_linear_A = new Matrix(2, 2);
    Matrix* p_simpson_quadratic_A = new Matrix(3, 3);
    Matrix* p_gauss_linear_A = new Matrix(2, 2);
    Matrix* p_gauss_quadratic_A = new Matrix(3, 3);

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            (*p_simpson_linear_A)(i+1, j+1) = 
                p_simpson_f1->IntegrateMatrixProduct(i, j, 2, p_linear);
            (*p_gauss_linear_A)(i+1, j+1) = 
                p_gauss_f1->IntegrateMatrixProduct(i, j, 2, p_linear);
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            (*p_simpson_quadratic_A)(i+1, j+1) =
                p_simpson_f1->IntegrateMatrixProduct(i, j, 3, p_quadratic);
            (*p_gauss_quadratic_A)(i+1, j+1) =
                p_gauss_f1->IntegrateMatrixProduct(i, j, 3, p_quadratic);
        }
    }

    std::cout << std::endl << "Simpson's Rule" << std::endl;
    std::cout << "Linear:" << std::endl;
    std::cout << *p_simpson_linear_A;

    std::cout << "Quadratic:" << std::endl;
    std::cout << *p_simpson_quadratic_A;

    std::cout << std::endl << "Gauss-4-Point Rule" << std::endl;
    std::cout << "Linear:" << std::endl;
    std::cout << *p_gauss_linear_A;

    std::cout << "Quadratic:" << std::endl;
    std::cout << *p_gauss_quadratic_A;



    std::cout << std::endl << "Question 2civ - Gaussian Elimination" 
        << std::endl;

    Vector* p_simpson_linear_p = new Vector(2);
    Vector* p_simpson_quadratic_p = new Vector(3);
    Vector* p_gauss_linear_p = new Vector(2);
    Vector* p_gauss_quadratic_p = new Vector(3);

    GaussianElimination(p_simpson_linear_A, p_simpson_linear_p, 
        p_simpson_linear_f);
    GaussianElimination(p_simpson_quadratic_A, p_simpson_quadratic_p, 
        p_simpson_quadratic_f);
    GaussianElimination(p_gauss_linear_A, p_gauss_linear_p, 
        p_gauss_linear_f);
    GaussianElimination(p_gauss_quadratic_A, p_gauss_quadratic_p, 
        p_gauss_quadratic_f);

    std::cout << std::endl << "Simpson's Rule" << std::endl;
    std::cout << "Linear:" << std::endl;
    std::cout << *p_simpson_linear_p;

    std::cout << "Quadratic:" << std::endl;
    std::cout << *p_simpson_quadratic_p;

    std::cout << std::endl << "Gauss-4-Point Rule" << std::endl;
    std::cout << "Linear:" << std::endl;
    std::cout << *p_gauss_linear_p;

    std::cout << "Quadratic:" << std::endl;
    std::cout << *p_gauss_quadratic_p;


    delete p_simpson_f1;
    delete p_gauss_f1;
    delete p_linear;
    delete p_quadratic;
    delete p_simpson_linear_A;
    delete p_simpson_linear_p;
    delete p_simpson_linear_f;
    delete p_simpson_quadratic_A;
    delete p_simpson_quadratic_p;
    delete p_simpson_quadratic_f;
    delete p_gauss_linear_A;
    delete p_gauss_linear_p;
    delete p_gauss_linear_f;
    delete p_gauss_quadratic_A;
    delete p_gauss_quadratic_p;
    delete p_gauss_quadratic_f;

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