#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char* argv[])
{
    /* Defines 4 matrices and does operations on them*/
    double A[2][2] = {{1.0, 6.0}, {2.0, 2.0}}, B[2][2] = {{2.0, 5.0}, {1.0, 8.0}}, C[2][2], D[2][2];
    
    C[0][0] = A[0][0] + B[0][0];
    C[0][1] = A[0][1] + B[0][1];
    C[1][0] = A[1][0] + B[1][0];
    C[1][1] = A[1][1] + B[1][1];
    
    std::cout << "A+B is\n" << C[0][0] << " " << C[0][1] <<"\n" << C[1][0] << " " << C[1][1] << "\n";
    
    D[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    D[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    D[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    D[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
    
    std::cout << "A*B is\n" << D[0][0] << " " << D[0][1] <<"\n" << D[1][0] << " " << D[1][1] << "\n";
    
}
