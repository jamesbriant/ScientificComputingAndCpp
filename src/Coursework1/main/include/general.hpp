#ifndef GENERALHEADERDEF
#define GENERALHEADERDEF

void CopyVector(int length, double* pVec, double* pNewVec);
void PrintVector(int length, double* pVec);
void PrintMatrix(int p, int q, double** pMatrix);
double** AllocateMatrix(int nrows, int ncols);
double** AllocateTridiagonalMatrix(int nrows);
void PopulateMatrix(int nrows, int ncols, double** pMatrix);
void PopulateVector0(int nrows, double* pVector);
double* Multiply(int nrows, int ncols, double** pM, double* px);
double* Multiply(int nrows, int ncols, double* px, double** pM);
double* MultiplyTridiagonalMatrix(int nrows, double** pM, double* px);
double* Add(int n, double* a, double* b);
double* Subtract(int n, double* a, double* b);
double* ScaleVector(int n, double a, double* pVec);
double InnerProduct(int n, double* pVec1, double* pVec2);
double Norm2(int n, double* pVec);
void DeallocateMatrix(int nrows, double** pMatrix);

#endif
