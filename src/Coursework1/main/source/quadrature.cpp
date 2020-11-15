#include "../include/general.hpp"
#include "../include/quadrature.hpp"

double** GenerateSimpsonsMesh(int n, double a, double b)
// returns n by 2 matrix of x mesh points and w weights
{
    // Calculate useful values
    int N = 2*n + 1;
    double h = (b - a)/(N - 1);

    double w1 = h/3;
    double w2 = 2*w1;
    double w3 = 2*w2;

    // instantiate the weights matrix
    double** p_Mesh = AllocateMatrix(N, 2);

    // Generate points x and weights w

    // Add the end points
    p_Mesh[0][0] = a;
    p_Mesh[0][1] = w1;
    p_Mesh[N-1][0] = b;
    p_Mesh[N-1][1] = w1;

    // Fill in the middle of the matrix
    for(int i=1; i<N-1; i++)
    {
        p_Mesh[i][0] = a + i*h;
        
        if(i % 2 == 1)
        {
            p_Mesh[i][1] = w3; // =4h/3
        }
        else
        {
            p_Mesh[i][1] = w2; // =2h/3
        }
    }

    return p_Mesh;
}

double ApplySimpsonsRule(int n, double a, double b, 
                         double (*pFunction)(double x))
// Apply Simpsons to function f on (a,b) with 2n+1 mesh points
{
    // Create mesh for integration approximation
    double** p_MeshData = GenerateSimpsonsMesh(n, a, b);

    int N = 2*n + 1;
    
    // implement Simpson's Rule
    double sum = 0;
    for(int i=0; i<N; i++)
    {
        sum += (*pFunction)(p_MeshData[i][0]) * p_MeshData[i][1];
    }

    // delete the local matrix
    DeallocateMatrix(N, p_MeshData);
    
    return sum;
}
