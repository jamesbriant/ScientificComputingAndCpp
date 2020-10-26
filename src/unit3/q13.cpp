#include <iostream>

int main()
{
    int N = 3;

    int** A;
    A = new int* [N];
    for(int i=0; i<N; i++)
    {
        A[i] = new int [N];
    }

    A[0][0] = 1; A[0][1] = 5; A[0][2] = 0;
    A[1][0] = 7; A[1][1] = 1; A[1][2] = 2;
    A[2][0] = 0; A[2][1] = 0; A[2][2] = 1;

    int* u;
    u = new int [N];
    u[0] = 1; u[1] = 2; u[2] = 3;

    int* Au;
    Au = new int [N];

    Au[0] = A[0][0] * u[0] + A[0][1] * u[1] + A[0][2] * u[2];
    Au[1] = A[1][0] * u[0] + A[1][1] * u[1] + A[1][2] * u[2];
    Au[2] = A[2][0] * u[0] + A[2][1] * u[1] + A[2][2] * u[2];

    std::cout << Au[0] << " " << Au[1] << " " << Au[2];

    delete A, u;

    return 0;
}