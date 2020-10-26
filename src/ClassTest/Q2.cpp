#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cassert>

void OutputMatrix(int** matrix, int noRows, int noCols, std::string filename);
int GetAlive(int** matrix, int i, int j);

int main()
{
    int m, K;
    do
    {
        std::cout << "Enter an odd number, m: " << std::endl;
        std::cin >> m;
    } while (m%2 != 1); // checks entered number is odd, ask again if even

    do
    {
        std::cout << "Enter a value for K, smaller than " << (m-1)/2;
        std::cout << ": " << std::endl;
        std::cin >> K;
    } while (K >= (m-1)/2); // Check value is small enough, ask again if not
    
    // Dynamically create the state matrices
    int** statesPrevious;
    statesPrevious = new int* [m];
    for(int i=0; i<m; i++)
    {
        statesPrevious[i] = new int [m];
        for(int j=0; j<m; j++)
        {
            statesPrevious[i][j] = 0;
        }
    }

    int** statesNext;
    statesNext = new int* [m];
    for(int i=0; i<m; i++)
    {
        statesNext[i] = new int [m];
        for(int j=0; j<m; j++)
        {
            statesNext[i][j] = 0;
        }
    }

    int gameType; // 0 for B1/S12, 1 for B2/S23

    do // Ask for game type, repeat until answer is 0 or 1
    {
        std::cout << "What came would you like to play?" << std::endl;
        std::cout << "Enter 0 for B1/S12 or enter 1 for B2/S23: " << std::endl;
        std::cin >> gameType;
    } while(gameType != 0 || gameType != 1);
    
    if(gameType == 0)
    {
        // B1/S12

        // INITIAL CONDITION: Enter 1 in center of grid
        statesPrevious[(m-1)/2][(m-1)/2] = 1;

        // Implement game
        for(int k=0; k<K; k++)
        {
            for(int i=1; i<=m-2; i++)
            {
                for(int j=1; j<=m-2; j++)
                {
                    int alive = GetAlive(statesPrevious, i, j);

                    if(alive == 2 && statesPrevious[i][j] == 0)
                    // if dead and has enough alive neighbours
                    {
                        statesNext[i][j] == 1;
                    }
                    else if((alive == 2 || alive == 3) && 
                            statesPrevious[i][j] == 1)
                    // if alive and has enough alive neighbours
                    {
                        statesNext[i][j] == 1;
                    }
                }
            }

            statesPrevious = statesNext;
        }
    }
    else
    {
        // B2/S23

        // INITIAL CONDITION: Enter 3x3 grid of 1s in center of grid
        statesPrevious[((m-1)/2)-1][((m-1)/2)-1] = 1;
        statesPrevious[((m-1)/2)-1][((m-1)/2)] = 1;
        statesPrevious[((m-1)/2)-1][((m-1)/2)+1] = 1;
        statesPrevious[((m-1)/2)][((m-1)/2)-1] = 1;
        statesPrevious[((m-1)/2)][((m-1)/2)] = 1;
        statesPrevious[((m-1)/2)][((m-1)/2)+1] = 1;
        statesPrevious[((m-1)/2)+1][((m-1)/2)-1] = 1;
        statesPrevious[((m-1)/2)+1][((m-1)/2)] = 1;
        statesPrevious[((m-1)/2)+1][((m-1)/2)+1] = 1;

        // Implement game




    }
    



    OutputMatrix(statesPrevious, K+1, m, "matrix2.dat");

    // Delete the dynamically generated state matrix before close
    for(int i=0; i<K+1; i++)
    {
        delete statesPrevious[i];
        delete statesNext[i];
    }
    delete[] statesPrevious;
    delete[] statesNext;

    return 0;

}

int GetAlive(int** matrix, int i, int j)
{
    int counter = 0;

    for(int a=-1; a<=1; a++)
    {
        for(int b=-1; b<=1; b++)
        {
            if(matrix[i+a][j+b] == 1)
            {
                if(a==0 && b==0){
                    break;
                } 
                else
                {
                    counter += 1;
                }
            }
        }
    }

    return counter;
}

void OutputMatrix(int** matrix, int noRows, int noCols, std::string filename)
{
    //Function to output a dynamically allocated matrix to a file.
    //Inputs:
    // matrix - pointer to the matrix
    // noRows - no rows of the matrix
    // noCols - no columns of the matrix
    // filename - file name to output to.

    std::ofstream outputFile;
    outputFile.open(filename);

    for (int k=0;k < noRows;k++)
    {
        for (int l=0;l < noCols;l++)
        {
            outputFile << matrix[k][l] << " ";
        }
        outputFile << std::endl;
    }

    outputFile.close();

}