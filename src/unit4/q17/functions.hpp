double** AllocateMatrix(int nrows, int ncols);
int PopulateMatrix(int nrows, int ncols, double** matrix);
double* Multiply(int nrows, int ncols, double** M, double* x);
double* Multiply(int nrows, int ncols, double* x, double** M);
void DeallocateMatrix(int nrows, double** matrix);