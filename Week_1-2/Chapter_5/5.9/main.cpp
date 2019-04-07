#include "5_9.h"
#include <iostream>

int main(int argc, char* argv[])
{
    int row=3, col=3;
    double **A = allocate_matrix(row, col);
    
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;
    A[2][0] = 7; A[2][1] = 8; A[2][2] = 9;
    
    double *b = new double [3];
    double *u = new double [3];
    
    b[0] = 2; b[1] = 5; b[2] = 9;
    
    solve3by3(A, b, u);
    
    freematrixmemory(row, A);
    delete[] b;
    delete[] u;
    
    return 0;
}
