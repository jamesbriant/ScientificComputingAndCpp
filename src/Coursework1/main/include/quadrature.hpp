#ifndef QUADRATUREHEADERDEF
#define QUADRATUREHEADERDEF

double** GenerateSimpsonsMesh(int n, double a, double b);
double ApplySimpsonsRule(int n, double a, double b, 
            double (*pFunction)(double x));
double ApplySimpsonsRule(int n, double a, double b,
            double (*pIntegrand)(double x, double h, double a, 
                double (*pUserFunction)(double x)),
            double (*pUserFunction)(double x));

#endif
