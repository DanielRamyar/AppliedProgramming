#include "5_6.h"
#include <iostream>

int main(int argc, char* argv[])
{
    int A_Rows=2, A_Cols=2;
    int B_Rows=2, B_Cols=2;
    
    // Define my matrix and vector
    double** A_mat = allocate_matrix(A_Rows, A_Cols);
    double** B_mat = allocate_matrix(B_Rows, B_Cols);
    double* V = new double [3];
    double* result = new double [B_Rows];
//    double** result = allocate_matrix(B_Rows, B_Cols);
    
    // Insert data in matrices and vector
    // B = 3 2
    //     7 4
    B_mat[0][0] = 3; B_mat[0][1] = 2;
    B_mat[1][0] = 7; B_mat[1][1] = 4;
    
    // A = 2 5
    //     5 6
    A_mat[0][0] = 2; A_mat[0][1] = 5;
    A_mat[1][0] = 5; A_mat[1][1] = 6;
    
    // V = 6 8
    V[0] = 6; V[1] = 8; V[2] = 0;
    
    double c = 4.0;
    
    Multiply(result, V, B_mat, 3, B_Rows, B_Cols);
    
    std::cout << result[0] << " " << result[1] << "\n";
//    std::cout << result[1][0] << " " << result[1][1] << "\n";
    
    // Deleting arrays
    freematrixmemory(A_Rows, A_mat);
//    freematrixmemory(B_Rows, B_mat);
//    freematrixmemory(B_Rows, result);
    delete[] V;
    
    
    return 0;
}
