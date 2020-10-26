#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cassert>

void OutputMatrix(int** matrix, int noRows, int noCols, std::string filename);

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
    
    // Dynamically create the state matrix
    int** states;
    states = new int* [K+1];
    for(int i=0; i<K+1; i++)
    {
        states[i] = new int [m];
        for(int j=0; j<m; j++)
        {
            states[i][j] = 0;
        }
    }



    // INITIAL CONDITION: Enter 1 in middle of first row
    states[0][(m-1)/2] = 1;

    // RUN THE SIMULATION
    for(int k=1; k<=K; k++) // iterate over the time steps
    {
        for(int i=1; i<=m-2; i++) 
        // add buffer zone of size 1 at each end by starting at i=1 and ending
        // at i=m-2
        {
            if(states[k-1][i-1] == states[k-1][i+1]) // Impletement rule
            {
                states[k][i] = 0;
            }
            else
            {
                states[k][i] = 1;
            }
        }
    }


    OutputMatrix(states, K+1, m, "matrix.dat");

    // Delete the dynamically generated state matrix before close
    for(int i=0; i<K+1; i++)
    {
        delete states[i];
    }
    delete[] states;

    return 0;

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