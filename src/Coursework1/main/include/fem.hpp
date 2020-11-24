#ifndef FEMHEADERDEF
#define FEMHEADERDEF

double* GenerateFEMMesh(double a, double b, int N);
double CalculatePhiValue(int k, double x, double h, double a, bool derivative);
void SetupStiffnessAndLoadArrays(int n, double** pA, double* pF, double* pMesh, 
        double A, double B, double (*b)(double x), double (*c)(double x),
        double (*f)(double x));
double Integrand00b(double x, double h, double a, double (*b)(double x));
double Integrand00c(double x, double h, double a, double (*c)(double x));
double Integrand01b(double x, double h, double a, double (*b)(double x));
double Integrand01c(double x, double h, double a, double (*c)(double x));
double Integrand10b(double x, double h, double a, double (*b)(double x));
double Integrand10c(double x, double h, double a, double (*c)(double x));
double Integrand11b(double x, double h, double a, double (*b)(double x));
double Integrand11c(double x, double h, double a, double (*c)(double x));
double IntegrandEll0(double x, double h, double a, double (*f)(double x));
double IntegrandEll1(double x, double h, double a, double (*f)(double x));
void CalculateU(int n, double* puEstimate, double** pA, double* pu0, 
        double* pF, double tol, int maxIter);
double* CalculateUh(int n, double A, double B, double* pU);
void SaveData(int n, double* pMesh, double* pSolution);

#endif