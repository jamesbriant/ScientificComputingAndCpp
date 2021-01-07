#include <iostream>
#include <cmath>
#include <fstream>
#include "Gauss4Point.hpp"
#include "BestL2Fit.hpp"

// g++ *.cpp -o Q3.exe

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
    Gauss4Point* p_gauss_f2 = new Gauss4Point(0.0, 1.0, f2);
    Gauss4Point* p_gauss_f3 = new Gauss4Point(0.0, 1.0, f3);
    Gauss4Point* p_gauss_f4 = new Gauss4Point(0.0, 1.0, f4);

    BestL2Fit* p_bestfit_f1 = 
        new BestL2Fit(f1, p_gauss_f1, 0.0, 1.0, 4, "data/BestFitf1.dat");
    BestL2Fit* p_bestfit_f2 = 
        new BestL2Fit(f2, p_gauss_f2, 0.0, 1.0, 4, "data/BestFitf2.dat");
    BestL2Fit* p_bestfit_f3 = 
        new BestL2Fit(f3, p_gauss_f3, 0.0, 1.0, 4, "data/BestFitf3.dat");
    BestL2Fit* p_bestfit_f4 = 
        new BestL2Fit(f4, p_gauss_f4, 0.0, 1.0, 4, "data/BestFitf4.dat");

    // make approximates, data saved to file
    p_bestfit_f1->Approximate(101);
    p_bestfit_f2->Approximate(101);
    p_bestfit_f3->Approximate(101);
    p_bestfit_f4->Approximate(101);

    // read data from files
    Vector* p_bestfit_f1_data = new Vector(101);
    Vector* p_bestfit_f2_data = new Vector(101);
    Vector* p_bestfit_f3_data = new Vector(101);
    Vector* p_bestfit_f4_data = new Vector(101);
    ReadData("data/BestFitf1.dat", p_bestfit_f1_data);
    ReadData("data/BestFitf2.dat", p_bestfit_f2_data);
    ReadData("data/BestFitf3.dat", p_bestfit_f3_data);
    ReadData("data/BestFitf4.dat", p_bestfit_f4_data);

    // calculate the true function values
    Vector* p_true_f1 = new Vector(101);
    Vector* p_true_f2 = new Vector(101);
    Vector* p_true_f3 = new Vector(101);
    Vector* p_true_f4 = new Vector(101);
    for(int i = 0; i < 101; i++)
    {
        (*p_true_f1)[i] = f1(i*0.01);
        (*p_true_f2)[i] = f2(i*0.01);
        (*p_true_f3)[i] = f3(i*0.01);
        (*p_true_f4)[i] = f4(i*0.01);
    }
    
    // output the maximum errors
    std::cout << "f1" << std::endl;
    std::cout << "maximum error: " << 
        MaxError(p_bestfit_f1_data, p_true_f1) << std::endl;
    std::cout << "2Norm: " << 
        L2Norm(*p_bestfit_f1_data, *p_true_f1) << std::endl;

    std::cout << std::endl << "f2" << std::endl;
    std::cout << "maximum error: " << 
        MaxError(p_bestfit_f2_data, p_true_f2) << std::endl;
    std::cout << "2Norm: " << 
        L2Norm(*p_bestfit_f2_data, *p_true_f2) << std::endl;

    std::cout << std::endl << "f3" << std::endl;
    std::cout << "maximum error: " << 
        MaxError(p_bestfit_f3_data, p_true_f3) << std::endl;
    std::cout << "2Norm: " << 
        L2Norm(*p_bestfit_f3_data, *p_true_f3) << std::endl;

    std::cout << std::endl << "f4" << std::endl;
    std::cout << "maximum error: " << 
        MaxError(p_bestfit_f4_data, p_true_f4) << std::endl;
    std::cout << "2Norm: " << 
        L2Norm(*p_bestfit_f4_data, *p_true_f4) << std::endl;



    // clean up
    delete p_bestfit_f1_data;
    delete p_bestfit_f2_data;
    delete p_bestfit_f3_data;
    delete p_bestfit_f4_data;
    //delete p_true_f1;
    delete p_true_f2;
    delete p_true_f3;
    delete p_true_f4;
    delete p_bestfit_f1;
    delete p_bestfit_f2;
    delete p_bestfit_f3;
    delete p_bestfit_f4;
    delete p_gauss_f1;
    delete p_gauss_f2;
    delete p_gauss_f3;
    delete p_gauss_f4;

    // Find the best quartic polynomial to approximate f1
    Gauss4Point* p_gauss_f1_quartic = new Gauss4Point(0.0, 1.0, f1);
    BestL2Fit* p_bestfit_f1_quartic = 
        new BestL2Fit(f1, p_gauss_f1_quartic, 0.0, 1.0, 5, "data/BestFitf1Quartic.dat");
    p_bestfit_f1_quartic->Approximate(101);
    Vector* p_bestfit_f1_quartic_data = new Vector(101);
    ReadData("data/BestFitf1.dat", p_bestfit_f1_quartic_data);

    std::cout << std::endl << "f1 - Quartic approximation" << std::endl;
    std::cout << "maximum error: " << 
        MaxError(p_bestfit_f1_quartic_data, p_true_f1) << std::endl;
    std::cout << "2Norm: " << 
        L2Norm(*p_bestfit_f1_quartic_data, *p_true_f1) << std::endl;

    delete p_gauss_f1_quartic;
    delete p_bestfit_f1_quartic;
    delete p_bestfit_f1_quartic_data;
    delete p_true_f1;

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
void ReadData(std::string fileName, Vector* pData)
{
    std::ifstream readFile; // Define Input stream
    readFile.open(fileName); // Open file
    //assert(readFile.is_open()); // Check file is open

    double dump;
  
    for (int i=0; i<101; i++)
    {
        readFile >> dump >> (*pData)[i];
    }
  
    readFile.close();
}

// calculate the maximum error at the evaluated points
double MaxError(Vector* pEstimate, Vector* pTrueSolution)
{
    double max_error = 0.0;

    for(int i=0; i<length(*pEstimate); i++)
    {
        if(fabs(pEstimate->Read(i) - pTrueSolution->Read(i)) > max_error)
        {
            max_error = fabs(pEstimate->Read(i) - pTrueSolution->Read(i));
        }
    }

    return max_error;
}

// calculate the L2-norm of the difference between Vectors pA and pB
double L2Norm(Vector& pA, Vector& pB)
{
    Vector* p_difference = new Vector(101);
    *p_difference = pA - pB;
    double output = sqrt(p_difference->ScalarProduct(*p_difference)/101.0);

    delete p_difference;
    return output;
}