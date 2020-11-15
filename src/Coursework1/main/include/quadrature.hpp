#ifndef QUADRATUREHEADERDEF
#define QUADRATUREHEADERDEF

double** GenerateSimpsonsMesh(int n, double a, double b);
double ApplySimpsonsRule(int n, double a, double b, 
                         double (*pFunction)(double x));

#endif
