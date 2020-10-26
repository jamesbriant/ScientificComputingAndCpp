#include <iostream>

auto subtractMatrix(int &matrix1[][], int &matrix2[][])
{
    int elementSize = sizeof(matrix1[0][0]);
    int elementCount = sizeof(*matrix1)/elementSize;
    int rowCount = elementCount/(sizeof(matrix1[0])/elementSize);
    int colCount = elementCount/rowCount;

    int** output;
    output = new int* [rowCount];
    for(int i=0; i<rowCount; i++)
    {
        output[i] = new int [colCount];
    }

    for(int i=0; i<rowCount; i++)
    {
        for(int j=0; j<colCount; j++)
        {
            output[i][j] = matrix1[i][j] - matrix2[1][j];
        }
    }

    return &output;
}

int main(int argc, char* argv[])
{
    int u[3] = {1, 2, 3};
    int v[3] = {6, 5, 4};

    int A[3][3] = {
        {1, 5, 0},
        {7, 1, 2},
        {0, 0, 1}
    };
    int B[3][3] = {
        {-2, 0, 1},
        {1, 0, 0},
        {4, 1, 0}
    };
    
    //std::cout << u - v << std::endl;
    std::cout << subtractMatrix(A, B)[0][0] << std::endl;
    return 0;
}