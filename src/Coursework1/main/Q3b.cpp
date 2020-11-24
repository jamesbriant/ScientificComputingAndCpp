#include <iostream>
#include <cmath>
#include "general.hpp"
#include "fem.hpp"

double f(double x);
double b(double x);
double c(double x);

int main()
{
    //
    double tol = 1e-10;
    int maxIter = 1000;

    // define the ODE problem over (0,1)
    double x0 = 0.0;
    double x1 = 1.0;

    // Define the boundary values
    double A = 0.0;
    double B = 1.0;

    // Number of elements
    int N = 100;

    // Set up the FEM mesh
    double* p_Mesh;
    p_Mesh = new double[N+1];
    p_Mesh = GenerateFEMMesh(x0, x1, N);

    // Set up stiffness and load arrays
    double* p_F;
    p_F = new double[N-1];
    double** p_A;
    p_A = AllocateTridiagonalMatrix(N-1);

    SetupStiffnessAndLoadArrays(N-1, p_A, p_F, p_Mesh, A, B, &b, &c, &f);

    // Solve the system of equations
    // Set up initial estimate of U
    double* p_U0;
    p_U0 = new double[N-1];
    PopulateVector0(N-1, p_U0);
    // numerically solve the equations
    double* p_U;
    p_U = new double[N-1];
    CalculateU(N-1, p_U, p_A, p_U0, p_F, tol, maxIter);

    // Generate the numerical approximation for u(x)
    double* p_Solution = CalculateUh(N-1, A, B, p_U);

    // Save the solution to a file
    SaveData(N+1, p_Mesh, p_Solution);

    DeallocateMatrix(N-1, p_A);
    delete[] p_Mesh, p_F, p_U, p_U0, p_Solution;

    return 0;
}

double f(double x)
// Defined as in the question
{
    return 0.0;
}

double b(double x)
// Defined as in the question
{
    return 0.0;
}

double c(double x)
// Defined as in the question
{
    return 100*sin(10*M_PI*x);
}
