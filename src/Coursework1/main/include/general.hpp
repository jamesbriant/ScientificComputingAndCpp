#ifndef GENERALHEADERDEF
#define GENERALHEADERDEF

void CopyVector(int length, double* pVec, double* pNewVec);
void PrintVector(int length, double* pVec);
void PrintMatrix(int p, int q, double** pMatrix);
double** AllocateMatrix(int nrows, int ncols);
void PopulateMatrix(int nrows, int ncols, double** pMatrix);
double* Multiply(int nrows, int ncols, double** pM, double* px);
double* Multiply(int nrows, int ncols, double* px, double** pM);
void DeallocateMatrix(int nrows, double** pMatrix);

#endif
