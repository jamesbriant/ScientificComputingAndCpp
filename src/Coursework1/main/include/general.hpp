#ifndef GENERALHEADERDEF
#define GENERALHEADERDEF

void CopyVector(int length, double* pVec, double* pNewVec);
void PrintVector(int length, double* pVec);
void PrintMatrix(int p, int q, double** pMatrix);
double** AllocateMatrix(int nrows, int ncols);
double** AllocateTridiagonalMatrix(int nrows);
void PopulateMatrix(int nrows, int ncols, double** pMatrix);
void PopulateVector(int nrows, double* pVector);
void PopulateVector0(int nrows, double* pVector);
void Multiply(int nrows, double* pMx, int ncols, double** pM, double* px);
void Multiply(int nrows, double* pxM, int ncols, double* px, double** pM);
void MultiplyTridiagonalMatrix(int nrows, double* pMx, double** pM, double* px);
void Add(int n, double* pSum, double* pa, double* pb);
void Subtract(int n, double* pDiff, double* pa, double* pb);
void ScaleVector(int n, double* pScaledVec, double a, double* pVec);
double InnerProduct(int n, double* pVec1, double* pVec2);
double Norm2(int n, double* pVec);
void DeallocateMatrix(int nrows, double** pMatrix);

#endif
