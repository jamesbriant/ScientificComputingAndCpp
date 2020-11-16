#ifndef LINEAR_ALGEBRAHEADERDEF
#define LINEAR_ALGEBRAHEADERDEF

double* ApplyBiGCstab(int n, double** pA, double* px0, double* pb, double tol);
double* CalculateR(int n, double** pA, double* px0, double* pb);

#endif