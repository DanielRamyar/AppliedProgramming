#include "5_10.h"
#include <iostream>

int main(int argc, char* argv[])
{
    int row=4, col=4;
    double **A = allocate_matrix(row, col);
    
    A[0][0] = 0.02; A[0][1] = 0.01; A[0][2] = 0; A[0][3] = 0;
    A[1][0] = 1; A[1][1] = 2; A[1][2] = 1; A[1][3] = 0;
    A[2][0] = 0; A[2][1] = 1; A[2][2] = 2; A[2][3] = 1;
    A[3][0] = 0; A[3][1] = 0; A[3][2] = 100; A[3][3] = 200;
    
    double *b = new double [4];
    double *u = new double [4];
    
    b[0] = 0.02; b[1] = 1; b[2] = 4; b[3] = 800;
    
    guassian_elimination(A, b, u, 4);
    
    freematrixmemory(row, A);
    delete[] b;
    delete[] u;
    
    return 0;
}
