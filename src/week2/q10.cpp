#include <iostream>

int subtractMatrix(int matrix1[], int matrix2[])
{
    
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
    
    std::cout << u - v << std::endl;

    return 0;
}