#include <iostream>
#include <cmath>
#include <fstream>
#include "Gauss4Point.hpp"
#include "LocalBestL2Fit.hpp"

// g++ *.cpp -o Q4.exe

// define function protoypes
double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);
void ReadData(std::string FileName, Vector* p_data);
double MaxError(Vector* p_estimate, Vector* p_true_solution);
double L2Norm(Vector& p_a, Vector& p_b);

int main(int argc, char* argv[])
{
    Gauss4Point* p_gauss_f1 = new Gauss4Point(0.0, 1.0, f1);
    // Gauss4Point* p_gauss_f2 = new Gauss4Point(0.0, 1.0, f2);
    // Gauss4Point* p_gauss_f3 = new Gauss4Point(0.0, 1.0, f3);
    // Gauss4Point* p_gauss_f4 = new Gauss4Point(0.0, 1.0, f4);

    LocalBestL2Fit* p_bestfit_f1 = 
        new LocalBestL2Fit(f1, p_gauss_f1, 0.0, 1.0, 4, 4, 
            "data/BestFitf1.dat");


    delete p_gauss_f1;
    delete p_bestfit_f1;
    
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

// copy data at FileName to p_data
void ReadData(std::string FileName, Vector* p_data)
{
    std::ifstream readFile; // Define Input stream
    readFile.open(FileName); // Open file
    //assert(readFile.is_open()); // Check file is open

    double dump;
    //Vector* readin = new Vector(101);
  
    for (int i=0; i<101; i++)
    {
        readFile >> dump >> (*p_data)[i];
        //std::cout << readin->Read(i) << std::endl;
    }
  
    readFile.close();
}

double MaxError(Vector* p_estimate, Vector* p_true_solution)
{
    double max_error = 0.0;

    for(int i=0; i<length(*p_estimate); i++)
    {
        if(fabs(p_estimate->Read(i) - p_true_solution->Read(i)) > max_error)
        {
            max_error = fabs(p_estimate->Read(i) - p_true_solution->Read(i));
        }
    }

    return max_error;
}

double L2Norm(Vector& p_a, Vector& p_b)
{
    Vector* pDifference = new Vector(101);
    *pDifference = p_a - p_b;
    double output = sqrt(pDifference->ScalarProduct(*pDifference)/101.0);

    delete pDifference;
    return output;
}