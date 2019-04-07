#include <iostream>
#include <fstream>
#include <cassert>
int main(int argc, char* argv[])
{
    for (int h=0; h<1000000000; h++){
        int rows=2, cols=2;
        double** A;
        double** B;
        double** C;
        
        A = new double* [rows];
        B = new double* [rows];
        C = new double* [rows];
        
        for (int i=0; i<rows; i++) {
            A[i] = new double [cols];
            B[i] = new double [cols];
            C[i] = new double [cols];
        }
        
        for (int i=0; i<rows;i++) {
            for (int j=0; j<cols; j++) {
                A[i][j] = i+1;
                B[i][j] = 2*A[i][j];
                
                C[i][j] = A[i][j] + B[i][j];
                
    //            std::cout << A[i][j] << " " << i << " " << j << "\n";
    //            std::cout << B[i][j] << " " << i << " " << j << "\n";
    //            std::cout << "C " << C[i][j] << " " << i << " " << j << "\n";
            }
        }
        
        for (int i=0; i<rows;i++) {
            delete[] A[i];
            delete[] B[i];
            delete[] C[i];
        }
        delete[] A;
        delete[] B;
        delete[] C;
    }

    return 0;
}
