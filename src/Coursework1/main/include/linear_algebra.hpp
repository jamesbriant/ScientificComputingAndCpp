#ifndef LINEAR_ALGEBRAHEADERDEF
#define LINEAR_ALGEBRAHEADERDEF

double* ApplyBiGCstab(int n, double** pA, double* px0, double* pb, double tol,
                      int maxIter);
double* CalculateP(int n, double* pR, double* pP, double* pNu, double beta, 
                    double omega);

#endif