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
    std::cout << "Question 4bi" << std::endl;

    // create integrators
    Gauss4Point* p_gauss_f1 = new Gauss4Point(0.0, 1.0, f1);
    Gauss4Point* p_gauss_f2 = new Gauss4Point(0.0, 1.0, f2);
    Gauss4Point* p_gauss_f3 = new Gauss4Point(0.0, 1.0, f3);
    Gauss4Point* p_gauss_f4 = new Gauss4Point(0.0, 1.0, f4);

    LocalBestL2Fit* p_localbestfit_f1_linear5 = 
        new LocalBestL2Fit(f1, p_gauss_f1, 0.0, 1.0, 2, 5, 
            "data/LocalBestFitf1Linear5.dat");
    LocalBestL2Fit* p_localbestfit_f2_linear5 = 
        new LocalBestL2Fit(f2, p_gauss_f2, 0.0, 1.0, 2, 5, 
            "data/LocalBestFitf2Linear5.dat");
    LocalBestL2Fit* p_localbestfit_f3_linear5 = 
        new LocalBestL2Fit(f3, p_gauss_f3, 0.0, 1.0, 2, 5, 
            "data/LocalBestFitf3Linear5.dat");
    LocalBestL2Fit* p_localbestfit_f4_linear5 = 
        new LocalBestL2Fit(f4, p_gauss_f4, 0.0, 1.0, 2, 5, 
            "data/LocalBestFitf4Linear5.dat");
    
    p_localbestfit_f1_linear5->Approximate(101);
    p_localbestfit_f2_linear5->Approximate(101);
    p_localbestfit_f3_linear5->Approximate(101);
    p_localbestfit_f4_linear5->Approximate(101);

    // read data from files
    Vector* p_localbestfit_f1_linear5_data = new Vector(101);
    Vector* p_localbestfit_f2_linear5_data = new Vector(101);
    Vector* p_localbestfit_f3_linear5_data = new Vector(101);
    Vector* p_localbestfit_f4_linear5_data = new Vector(101);
    ReadData("data/LocalBestFitf1Linear5.dat", p_localbestfit_f1_linear5_data);
    ReadData("data/LocalBestFitf2Linear5.dat", p_localbestfit_f2_linear5_data);
    ReadData("data/LocalBestFitf3Linear5.dat", p_localbestfit_f3_linear5_data);
    ReadData("data/LocalBestFitf4Linear5.dat", p_localbestfit_f4_linear5_data);

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
    std::cout << "f1, 5 intervals, linear approximation" << std::endl;
    std::cout << "maximum error: " << 
        MaxError(p_localbestfit_f1_linear5_data, p_true_f1) << std::endl;
    std::cout << "2Norm: " << 
        L2Norm(*p_localbestfit_f1_linear5_data, *p_true_f1) << std::endl;

    std::cout << std::endl << "f2, 5 intervals, linear approximation" << 
        std::endl;
    std::cout << "maximum error: " << 
        MaxError(p_localbestfit_f2_linear5_data, p_true_f2) << std::endl;
    std::cout << "2Norm: " << 
        L2Norm(*p_localbestfit_f2_linear5_data, *p_true_f2) << std::endl;

    std::cout << std::endl << "f3, 5 intervals, linear approximation" << 
        std::endl;
    std::cout << "maximum error: " << 
        MaxError(p_localbestfit_f3_linear5_data, p_true_f3) << std::endl;
    std::cout << "2Norm: " << 
        L2Norm(*p_localbestfit_f3_linear5_data, *p_true_f3) << std::endl;

    std::cout << std::endl << "f4, 5 intervals, linear approximation" << 
        std::endl;
    std::cout << "maximum error: " << 
        MaxError(p_localbestfit_f4_linear5_data, p_true_f4) << std::endl;
    std::cout << "2Norm: " << 
        L2Norm(*p_localbestfit_f4_linear5_data, *p_true_f4) << std::endl;

    // clean up
    delete p_localbestfit_f1_linear5_data;
    delete p_localbestfit_f2_linear5_data;
    delete p_localbestfit_f3_linear5_data;
    delete p_localbestfit_f4_linear5_data;
    delete p_localbestfit_f1_linear5;
    delete p_localbestfit_f2_linear5;
    delete p_localbestfit_f3_linear5;
    delete p_localbestfit_f4_linear5;



    std::cout << std::endl << "Question 4bii" << std::endl;

    LocalBestL2Fit* p_localbestfit_f1_linear2 = 
        new LocalBestL2Fit(f1, p_gauss_f1, 0.0, 1.0, 2, 2, 
            "data/LocalBestFitf1Linear2.dat");
    LocalBestL2Fit* p_localbestfit_f2_linear2 = 
        new LocalBestL2Fit(f2, p_gauss_f2, 0.0, 1.0, 2, 2, 
            "data/LocalBestFitf2Linear2.dat");
    LocalBestL2Fit* p_localbestfit_f3_linear2 = 
        new LocalBestL2Fit(f3, p_gauss_f3, 0.0, 1.0, 2, 2, 
            "data/LocalBestFitf3Linear2.dat");
    LocalBestL2Fit* p_localbestfit_f4_linear2 = 
        new LocalBestL2Fit(f4, p_gauss_f4, 0.0, 1.0, 2, 2, 
            "data/LocalBestFitf4Linear2.dat");

    LocalBestL2Fit* p_localbestfit_f1_linear4 = 
        new LocalBestL2Fit(f1, p_gauss_f1, 0.0, 1.0, 2, 4, 
            "data/LocalBestFitf1Linear4.dat");
    LocalBestL2Fit* p_localbestfit_f2_linear4 = 
        new LocalBestL2Fit(f2, p_gauss_f2, 0.0, 1.0, 2, 4, 
            "data/LocalBestFitf2Linear4.dat");
    LocalBestL2Fit* p_localbestfit_f3_linear4 = 
        new LocalBestL2Fit(f3, p_gauss_f3, 0.0, 1.0, 2, 4, 
            "data/LocalBestFitf3Linear4.dat");
    LocalBestL2Fit* p_localbestfit_f4_linear4 = 
        new LocalBestL2Fit(f4, p_gauss_f4, 0.0, 1.0, 2, 4, 
            "data/LocalBestFitf4Linear4.dat");

    LocalBestL2Fit* p_localbestfit_f1_linear8 = 
        new LocalBestL2Fit(f1, p_gauss_f1, 0.0, 1.0, 2, 8, 
            "data/LocalBestFitf1Linear8.dat");
    LocalBestL2Fit* p_localbestfit_f2_linear8 = 
        new LocalBestL2Fit(f2, p_gauss_f2, 0.0, 1.0, 2, 8, 
            "data/LocalBestFitf2Linear8.dat");
    LocalBestL2Fit* p_localbestfit_f3_linear8 = 
        new LocalBestL2Fit(f3, p_gauss_f3, 0.0, 1.0, 2, 8, 
            "data/LocalBestFitf3Linear8.dat");
    LocalBestL2Fit* p_localbestfit_f4_linear8 = 
        new LocalBestL2Fit(f4, p_gauss_f4, 0.0, 1.0, 2, 8, 
            "data/LocalBestFitf4Linear8.dat");

    LocalBestL2Fit* p_localbestfit_f1_cubic2 = 
        new LocalBestL2Fit(f1, p_gauss_f1, 0.0, 1.0, 4, 2, 
            "data/LocalBestFitf1Cubic2.dat");
    LocalBestL2Fit* p_localbestfit_f2_cubic2 = 
        new LocalBestL2Fit(f2, p_gauss_f2, 0.0, 1.0, 4, 2, 
            "data/LocalBestFitf2Cubic2.dat");
    LocalBestL2Fit* p_localbestfit_f3_cubic2 = 
        new LocalBestL2Fit(f3, p_gauss_f3, 0.0, 1.0, 4, 2, 
            "data/LocalBestFitf3Cubic2.dat");
    LocalBestL2Fit* p_localbestfit_f4_cubic2 = 
        new LocalBestL2Fit(f4, p_gauss_f4, 0.0, 1.0, 4, 2, 
            "data/LocalBestFitf4Cubic2.dat");

    LocalBestL2Fit* p_localbestfit_f1_cubic4 = 
        new LocalBestL2Fit(f1, p_gauss_f1, 0.0, 1.0, 4, 4, 
            "data/LocalBestFitf1Cubic4.dat");
    LocalBestL2Fit* p_localbestfit_f2_cubic4 = 
        new LocalBestL2Fit(f2, p_gauss_f2, 0.0, 1.0, 4, 4, 
            "data/LocalBestFitf2Cubic4.dat");
    LocalBestL2Fit* p_localbestfit_f3_cubic4 = 
        new LocalBestL2Fit(f3, p_gauss_f3, 0.0, 1.0, 4, 4, 
            "data/LocalBestFitf3Cubic4.dat");
    LocalBestL2Fit* p_localbestfit_f4_cubic4 = 
        new LocalBestL2Fit(f4, p_gauss_f4, 0.0, 1.0, 4, 4, 
            "data/LocalBestFitf4Cubic4.dat");

    LocalBestL2Fit* p_localbestfit_f1_cubic8 = 
        new LocalBestL2Fit(f1, p_gauss_f1, 0.0, 1.0, 4, 8, 
            "data/LocalBestFitf1Cubic8.dat");
    LocalBestL2Fit* p_localbestfit_f2_cubic8 = 
        new LocalBestL2Fit(f2, p_gauss_f2, 0.0, 1.0, 4, 8, 
            "data/LocalBestFitf2Cubic8.dat");
    LocalBestL2Fit* p_localbestfit_f3_cubic8 = 
        new LocalBestL2Fit(f3, p_gauss_f3, 0.0, 1.0, 4, 8, 
            "data/LocalBestFitf3Cubic8.dat");
    LocalBestL2Fit* p_localbestfit_f4_cubic8 = 
        new LocalBestL2Fit(f4, p_gauss_f4, 0.0, 1.0, 4, 8, 
            "data/LocalBestFitf4Cubic8.dat");

    // make approximates, data saved to file
    p_localbestfit_f1_linear2->Approximate(101);
    p_localbestfit_f2_linear2->Approximate(101);
    p_localbestfit_f3_linear2->Approximate(101);
    p_localbestfit_f4_linear2->Approximate(101);

    p_localbestfit_f1_linear4->Approximate(101);
    p_localbestfit_f2_linear4->Approximate(101);
    p_localbestfit_f3_linear4->Approximate(101);
    p_localbestfit_f4_linear4->Approximate(101);

    p_localbestfit_f1_linear8->Approximate(101);
    p_localbestfit_f2_linear8->Approximate(101);
    p_localbestfit_f3_linear8->Approximate(101);
    p_localbestfit_f4_linear8->Approximate(101);

    p_localbestfit_f1_cubic2->Approximate(101);
    p_localbestfit_f2_cubic2->Approximate(101);
    p_localbestfit_f3_cubic2->Approximate(101);
    p_localbestfit_f4_cubic2->Approximate(101);

    p_localbestfit_f1_cubic4->Approximate(101);
    p_localbestfit_f2_cubic4->Approximate(101);
    p_localbestfit_f3_cubic4->Approximate(101);
    p_localbestfit_f4_cubic4->Approximate(101);

    p_localbestfit_f1_cubic8->Approximate(101);
    p_localbestfit_f2_cubic8->Approximate(101);
    p_localbestfit_f3_cubic8->Approximate(101);
    p_localbestfit_f4_cubic8->Approximate(101);

    // read data from files
    Vector* p_localbestfit_f1_linear2_data = new Vector(101);
    Vector* p_localbestfit_f2_linear2_data = new Vector(101);
    Vector* p_localbestfit_f3_linear2_data = new Vector(101);
    Vector* p_localbestfit_f4_linear2_data = new Vector(101);
    ReadData("data/LocalBestFitf1Linear2.dat", p_localbestfit_f1_linear2_data);
    ReadData("data/LocalBestFitf2Linear2.dat", p_localbestfit_f2_linear2_data);
    ReadData("data/LocalBestFitf3Linear2.dat", p_localbestfit_f3_linear2_data);
    ReadData("data/LocalBestFitf4Linear2.dat", p_localbestfit_f4_linear2_data);
    Vector* p_localbestfit_f1_linear4_data = new Vector(101);
    Vector* p_localbestfit_f2_linear4_data = new Vector(101);
    Vector* p_localbestfit_f3_linear4_data = new Vector(101);
    Vector* p_localbestfit_f4_linear4_data = new Vector(101);
    ReadData("data/LocalBestFitf1Linear4.dat", p_localbestfit_f1_linear4_data);
    ReadData("data/LocalBestFitf2Linear4.dat", p_localbestfit_f2_linear4_data);
    ReadData("data/LocalBestFitf3Linear4.dat", p_localbestfit_f3_linear4_data);
    ReadData("data/LocalBestFitf4Linear4.dat", p_localbestfit_f4_linear4_data);
    Vector* p_localbestfit_f1_linear8_data = new Vector(101);
    Vector* p_localbestfit_f2_linear8_data = new Vector(101);
    Vector* p_localbestfit_f3_linear8_data = new Vector(101);
    Vector* p_localbestfit_f4_linear8_data = new Vector(101);
    ReadData("data/LocalBestFitf1Linear8.dat", p_localbestfit_f1_linear8_data);
    ReadData("data/LocalBestFitf2Linear8.dat", p_localbestfit_f2_linear8_data);
    ReadData("data/LocalBestFitf3Linear8.dat", p_localbestfit_f3_linear8_data);
    ReadData("data/LocalBestFitf4Linear8.dat", p_localbestfit_f4_linear8_data);
    Vector* p_localbestfit_f1_cubic2_data = new Vector(101);
    Vector* p_localbestfit_f2_cubic2_data = new Vector(101);
    Vector* p_localbestfit_f3_cubic2_data = new Vector(101);
    Vector* p_localbestfit_f4_cubic2_data = new Vector(101);
    ReadData("data/LocalBestFitf1Cubic2.dat", p_localbestfit_f1_cubic2_data);
    ReadData("data/LocalBestFitf2Cubic2.dat", p_localbestfit_f2_cubic2_data);
    ReadData("data/LocalBestFitf3Cubic2.dat", p_localbestfit_f3_cubic2_data);
    ReadData("data/LocalBestFitf4Cubic2.dat", p_localbestfit_f4_cubic2_data);
    Vector* p_localbestfit_f1_cubic4_data = new Vector(101);
    Vector* p_localbestfit_f2_cubic4_data = new Vector(101);
    Vector* p_localbestfit_f3_cubic4_data = new Vector(101);
    Vector* p_localbestfit_f4_cubic4_data = new Vector(101);
    ReadData("data/LocalBestFitf1Cubic4.dat", p_localbestfit_f1_cubic4_data);
    ReadData("data/LocalBestFitf2Cubic4.dat", p_localbestfit_f2_cubic4_data);
    ReadData("data/LocalBestFitf3Cubic4.dat", p_localbestfit_f3_cubic4_data);
    ReadData("data/LocalBestFitf4Cubic4.dat", p_localbestfit_f4_cubic4_data);
    Vector* p_localbestfit_f1_cubic8_data = new Vector(101);
    Vector* p_localbestfit_f2_cubic8_data = new Vector(101);
    Vector* p_localbestfit_f3_cubic8_data = new Vector(101);
    Vector* p_localbestfit_f4_cubic8_data = new Vector(101);
    ReadData("data/LocalBestFitf1Cubic8.dat", p_localbestfit_f1_cubic8_data);
    ReadData("data/LocalBestFitf2Cubic8.dat", p_localbestfit_f2_cubic8_data);
    ReadData("data/LocalBestFitf3Cubic8.dat", p_localbestfit_f3_cubic8_data);
    ReadData("data/LocalBestFitf4Cubic8.dat", p_localbestfit_f4_cubic8_data);

    // output the maximum errors
    std::cout << "Linear Approximation, 2 intervals:" << std::endl;
    std::cout << "f1 - maximum error: " << 
        MaxError(p_localbestfit_f1_linear2_data, p_true_f1) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f1_linear2_data, *p_true_f1) << std::endl;
    std::cout << "f2 - maximum error: " << 
        MaxError(p_localbestfit_f2_linear2_data, p_true_f2) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f2_linear2_data, *p_true_f2) << std::endl;
    std::cout << "f3 - maximum error: " << 
        MaxError(p_localbestfit_f3_linear2_data, p_true_f3) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f3_linear2_data, *p_true_f3) << std::endl;
    std::cout << "f4 - maximum error: " << 
        MaxError(p_localbestfit_f4_linear2_data, p_true_f4) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f4_linear2_data, *p_true_f4) << std::endl;

    std::cout << std::endl;
    std::cout << "Linear Approximation, 4 intervals:" << std::endl;
    std::cout << "f1 - maximum error: " << 
        MaxError(p_localbestfit_f1_linear4_data, p_true_f1) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f1_linear4_data, *p_true_f1) << std::endl;
    std::cout << "f2 - maximum error: " << 
        MaxError(p_localbestfit_f2_linear4_data, p_true_f2) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f2_linear4_data, *p_true_f2) << std::endl;
    std::cout << "f3 - maximum error: " << 
        MaxError(p_localbestfit_f3_linear4_data, p_true_f3) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f3_linear4_data, *p_true_f3) << std::endl;
    std::cout << "f4 - maximum error: " << 
        MaxError(p_localbestfit_f4_linear4_data, p_true_f4) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f4_linear4_data, *p_true_f4) << std::endl;

    std::cout << std::endl;
    std::cout << "Linear Approximation, 8 intervals:" << std::endl;
    std::cout << "f1 - maximum error: " << 
        MaxError(p_localbestfit_f1_linear8_data, p_true_f1) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f1_linear8_data, *p_true_f1) << std::endl;
    std::cout << "f2 - maximum error: " << 
        MaxError(p_localbestfit_f2_linear8_data, p_true_f2) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f2_linear8_data, *p_true_f2) << std::endl;
    std::cout << "f3 - maximum error: " << 
        MaxError(p_localbestfit_f3_linear8_data, p_true_f3) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f3_linear8_data, *p_true_f3) << std::endl;
    std::cout << "f4 - maximum error: " << 
        MaxError(p_localbestfit_f4_linear8_data, p_true_f4) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f4_linear8_data, *p_true_f4) << std::endl;

    std::cout << std::endl;
    std::cout << "Cubic Approximation, 2 intervals:" << std::endl;
    std::cout << "f1 - maximum error: " << 
        MaxError(p_localbestfit_f1_cubic2_data, p_true_f1) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f1_cubic2_data, *p_true_f1) << std::endl;
    std::cout << "f2 - maximum error: " << 
        MaxError(p_localbestfit_f2_cubic2_data, p_true_f2) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f2_cubic2_data, *p_true_f2) << std::endl;
    std::cout << "f3 - maximum error: " << 
        MaxError(p_localbestfit_f3_cubic2_data, p_true_f3) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f3_cubic2_data, *p_true_f3) << std::endl;
    std::cout << "f4 - maximum error: " << 
        MaxError(p_localbestfit_f4_cubic2_data, p_true_f4) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f4_cubic2_data, *p_true_f4) << std::endl;

    std::cout << std::endl;
    std::cout << "Cubic Approximation, 4 intervals:" << std::endl;
    std::cout << "f1 - maximum error: " << 
        MaxError(p_localbestfit_f1_cubic4_data, p_true_f1) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f1_cubic4_data, *p_true_f1) << std::endl;
    std::cout << "f2 - maximum error: " << 
        MaxError(p_localbestfit_f2_cubic4_data, p_true_f2) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f2_cubic4_data, *p_true_f2) << std::endl;
    std::cout << "f3 - maximum error: " << 
        MaxError(p_localbestfit_f3_cubic4_data, p_true_f3) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f3_cubic4_data, *p_true_f3) << std::endl;
    std::cout << "f4 - maximum error: " << 
        MaxError(p_localbestfit_f4_cubic4_data, p_true_f4) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f4_cubic4_data, *p_true_f4) << std::endl;

    std::cout << std::endl;
    std::cout << "Cubic Approximation, 8 intervals:" << std::endl;
    std::cout << "f1 - maximum error: " << 
        MaxError(p_localbestfit_f1_cubic8_data, p_true_f1) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f1_cubic8_data, *p_true_f1) << std::endl;
    std::cout << "f2 - maximum error: " << 
        MaxError(p_localbestfit_f2_cubic8_data, p_true_f2) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f2_cubic8_data, *p_true_f2) << std::endl;
    std::cout << "f3 - maximum error: " << 
        MaxError(p_localbestfit_f3_cubic8_data, p_true_f3) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f3_cubic8_data, *p_true_f3) << std::endl;
    std::cout << "f4 - maximum error: " << 
        MaxError(p_localbestfit_f4_cubic8_data, p_true_f4) << ", 2Norm: " << 
        L2Norm(*p_localbestfit_f4_cubic8_data, *p_true_f4) << std::endl;

    

    // clean up
    delete p_gauss_f1;
    delete p_gauss_f2;
    delete p_gauss_f3;
    delete p_gauss_f4;
    delete p_true_f1;
    delete p_true_f2;
    delete p_true_f3;
    delete p_true_f4;

    delete p_localbestfit_f1_linear2;
    delete p_localbestfit_f2_linear2;
    delete p_localbestfit_f3_linear2;
    delete p_localbestfit_f4_linear2;
    delete p_localbestfit_f1_linear2_data;
    delete p_localbestfit_f2_linear2_data;
    delete p_localbestfit_f3_linear2_data;
    delete p_localbestfit_f4_linear2_data;
    delete p_localbestfit_f1_linear4;
    delete p_localbestfit_f2_linear4;
    delete p_localbestfit_f3_linear4;
    delete p_localbestfit_f4_linear4;
    delete p_localbestfit_f1_linear4_data;
    delete p_localbestfit_f2_linear4_data;
    delete p_localbestfit_f3_linear4_data;
    delete p_localbestfit_f4_linear4_data;
    delete p_localbestfit_f1_linear8;
    delete p_localbestfit_f2_linear8;
    delete p_localbestfit_f3_linear8;
    delete p_localbestfit_f4_linear8;
    delete p_localbestfit_f1_linear8_data;
    delete p_localbestfit_f2_linear8_data;
    delete p_localbestfit_f3_linear8_data;
    delete p_localbestfit_f4_linear8_data;

    delete p_localbestfit_f1_cubic2;
    delete p_localbestfit_f2_cubic2;
    delete p_localbestfit_f3_cubic2;
    delete p_localbestfit_f4_cubic2;
    delete p_localbestfit_f1_cubic2_data;
    delete p_localbestfit_f2_cubic2_data;
    delete p_localbestfit_f3_cubic2_data;
    delete p_localbestfit_f4_cubic2_data;
    delete p_localbestfit_f1_cubic4;
    delete p_localbestfit_f2_cubic4;
    delete p_localbestfit_f3_cubic4;
    delete p_localbestfit_f4_cubic4;
    delete p_localbestfit_f1_cubic4_data;
    delete p_localbestfit_f2_cubic4_data;
    delete p_localbestfit_f3_cubic4_data;
    delete p_localbestfit_f4_cubic4_data;
    delete p_localbestfit_f1_cubic8;
    delete p_localbestfit_f2_cubic8;
    delete p_localbestfit_f3_cubic8;
    delete p_localbestfit_f4_cubic8;
    delete p_localbestfit_f1_cubic8_data;
    delete p_localbestfit_f2_cubic8_data;
    delete p_localbestfit_f3_cubic8_data;
    delete p_localbestfit_f4_cubic8_data;

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