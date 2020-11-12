#include <iostream>
#include <cmath>

double FindMaxElement(int n, double* V);
void CopyVector(int length, double* vec, double* newVec);
void PrintVector(int n, double* solution);
double* RunJacobiMethod(int n, double* x0, double* b, double* params, 
                        double tol);
double* RunGaussSeidelMethod(int n, double* x0, double* b, double* params, 
                        double tol);
double* RunSORMethod(int n, double* x0, double* b, double* params,
                        double tol); // THIS HAS NOT BEEN FINISHED
double CalcEndPoint(double alpha, double betagamma, double x, double b);
double CalcMidPoint(double* params, double x0, double x2, double b);

int main(int argc, char* argv[])
{
    int n = 15;
    double h = 2.0/(n + 1);
    double alpha = -2.0*(1.0 + 2.0 * pow(h, 2));
    double beta = 1.0;
    double gamma = 1.0;

    double params[3] = {alpha, beta, gamma};

    double* x0;
    double* b;
    x0 = new double[n];
    b = new double[n];
    for(int i=0; i<n; i++)
    {
        x0[i] = 0.0;
        b[i] = 0.0;
    }
    b[0] = -1.0;
    b[n-1] = -1.0;

    double tol = 1e-6;

    double* solution;
    solution = RunGaussSeidelMethod(n, x0, b, params, tol);

    PrintVector(n, solution);

    delete[] x0, b, solution;

    return 0;
}

double* RunJacobiMethod(int n, double* x0, double* b, double* params, 
                        double tol)
{
    double alpha = params[0];
    double beta = params[1];
    double gamma = params[2];

    double** X;
    X = new double*[2];
    for(int k=0; k<2; k++)
    {
        X[k] = new double[n];

        for(int i=0; i<n; i++)
        {
            X[k][i] = x0[i];
        }
    }

    double* difference;
    double* temp;
    difference = new double[n];

    int counter = 0;
    do
    {
        X[1][0] = CalcEndPoint(alpha, gamma, X[0][1], b[0]);
        difference[0] = fabs(X[1][0] - X[0][0]);
        for(int k=1; k<n-1; k++)
        {
            X[1][k] = CalcMidPoint(params, X[0][k-1], X[0][k+1], b[k]);
            difference[k] = fabs(X[1][k] - X[0][k]);
        }
        X[1][n-1] = CalcEndPoint(alpha, beta, X[0][n-2], b[n-1]);
        difference[n-1] = fabs(X[1][n-1] - X[0][n-1]);

        temp = X[0];
        X[0] = X[1]; // let first row = second row, then repeat algorithm
        X[1] = temp;
        counter++;
    } while (FindMaxElement(n, difference) > tol && counter < 1000);

    double* output;
    output = new double[n];
    CopyVector(n, X[0], output);

    for(int k=0; k<2; k++)
    {
        delete[] X[k];
    }
    delete[] X, temp, difference;

    return output;
}

double* RunGaussSeidelMethod(int n, double* x0, double* b, double* params, 
                        double tol)
{
    double alpha = params[0];
    double beta = params[1];
    double gamma = params[2];

    double** X;
    X = new double*[2];
    for(int k=0; k<2; k++)
    {
        X[k] = new double[n];

        for(int i=0; i<n; i++)
        {
            X[k][i] = x0[i];
        }
    }

    double* difference;
    double* temp;
    difference = new double[n];

    int counter = 0;
    do
    {
        X[1][0] = CalcEndPoint(alpha, gamma, X[0][1], b[0]);
        difference[0] = fabs(X[1][0] - X[0][0]);
        for(int k=1; k<n-1; k++)
        {
            X[1][k] = CalcMidPoint(params, X[1][k-1], X[0][k+1], b[k]);
            difference[k] = fabs(X[1][k] - X[0][k]);
        }
        X[1][n-1] = CalcEndPoint(alpha, beta, X[1][n-2], b[n-1]);
        difference[n-1] = fabs(X[1][n-1] - X[0][n-1]);

        temp = X[0];
        X[0] = X[1]; // let first row = second row, then repeat algorithm
        X[1] = temp;
        counter++;
    } while (FindMaxElement(n, difference) > tol && counter < 1000);

    double* output;
    output = new double[n];
    CopyVector(n, X[0], output);

    for(int k=0; k<2; k++)
    {
        delete[] X[k];
    }
    delete[] X, temp, difference;

    return output;
}

double* RunSORMethod(int n, double* x0, double* b, double* params, 
                        double tol)
{
    double alpha = params[0];
    double beta = params[1];
    double gamma = params[2];

    double** X;
    X = new double*[2];
    for(int k=0; k<2; k++)
    {
        X[k] = new double[n];

        for(int i=0; i<n; i++)
        {
            X[k][i] = x0[i];
        }
    }

    double* difference;
    double* temp;
    difference = new double[n];

    int counter = 0;
    do
    {
        X[1][0] = CalcEndPoint(alpha, gamma, X[0][1], b[0]);
        difference[0] = fabs(X[1][0] - X[0][0]);
        for(int k=1; k<n-1; k++)
        {
            X[1][k] = CalcMidPoint(params, X[1][k-1], X[0][k+1], b[k]);
            difference[k] = fabs(X[1][k] - X[0][k]);
        }
        X[1][n-1] = CalcEndPoint(alpha, beta, X[1][n-2], b[n-1]);
        difference[n-1] = fabs(X[1][n-1] - X[0][n-1]);

        temp = X[0];
        X[0] = X[1]; // let first row = second row, then repeat algorithm
        X[1] = temp;
        counter++;
    } while (FindMaxElement(n, difference) > tol && counter < 1000);

    double* output;
    output = new double[n];
    CopyVector(n, X[0], output);

    for(int k=0; k<2; k++)
    {
        delete[] X[k];
    }
    delete[] X, temp, difference;

    return output;
}


void CopyVector(int length, double* vec, double* newVec)
{
    for (int k=0;k<length;k++)
    {
        newVec[k] = vec[k];
    }
}

double FindMaxElement(int n, double* V)
{
    if(n==1) return *V;

    double max = V[0];
    for(int i=1; i<n; i++)
    {
        if(max < V[i]) max = V[i];
    }

    return max;
}

void PrintVector(int n, double* solution)
{
    for(int i=0; i<n; i++)
    {
        std::cout << solution[i] << std::endl;
    }
}

double CalcEndPoint(double alpha, double betagamma, double x, double b)
{
    return((b - betagamma*x)/alpha);
}

double CalcMidPoint(double* params, double x0, double x2, double b)
{
    double alpha = params[0];
    double beta = params[1];
    double gamma = params[2];

    return((b - x0*beta - gamma*x2)/alpha);
}








