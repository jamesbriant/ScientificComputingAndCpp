#ifndef LINEAR_ALGEBRAHEADERDEF
#define LINEAR_ALGEBRAHEADERDEF

void CalculateR0(int n, double* pr0, double* pb, double** pA, double* px0);
bool CheckEarlyBreak(int n, double* pb, double** pA, double* ph, double tol);
void ApplyBiGCstab(int n, double* pxEstimate, double** pA, double* px0, 
                        double* pb, double tol, int maxIter);
void CalculateP(int n, double* pp, double* pr, double* pNu, double beta, 
                double omega);
void CalculateH(int n, double* ph, double* px, double alpha, double* pp);
void CalculateS(int n, double* ps, double* pr, double alpha, double* pNu);
void CalculateX(int n, double* px, double* ph, double omega, double* ps);
void CalculateR(int n, double* pr, double* ps, double omega, double* pt);

#endif