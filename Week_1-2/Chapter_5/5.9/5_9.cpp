#include "5_9.h"
#include <iostream>
#include <cmath>


double** allocate_matrix(int row, int col) {
    double** matrix = new double* [row];
    
    for (int i=0; i<row; i++) {
        matrix[i] = new double [col];
    }
    return matrix;
}

void freematrixmemory(int row, double** matrix) {
    for (int i=0; i<row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void pivot(double **A, double *b, int k) {
    
    double max=A[k][k];
    int temp=k;
    for (int n=k+1; n<3; n++){
        if (A[n][k] > max) {
            max = A[n][k];
            temp = n;
        }
        else {
            NULL;
        }
    }
    
    if (temp != k){
        double** P=allocate_matrix(3,3);
        int n=temp;
        
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if ((i==j) && (i!=k) && (j!=k) && (i!=n) && (j!=n)){
                    P[i][j] = 1;
                }
                else if ((i==k) && (j==n)){
                    P[i][j] = 1;
                }
                else if ((i==n) && (j==k)){
                    P[i][j] = 1;
                }
                else{
                    P[i][j] = 0;
                }
            }
        }
        
        temp=0;
        double** res1=allocate_matrix(3,3);
        
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                for (int k=0; k<3; k++) {
                    temp += P[i][k]*A[k][j];
                }
                res1[i][j] = temp;
                temp = 0;
            }
        }
        
        double *res2= new double [3];
        temp = 0;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                temp += P[i][j]*b[j];
            }
            res2[i] = temp;
            temp = 0;
        }
        
        for (int i=0; i<3; i++) {
            b[i] = res2[i];
            for (int j=0; j<3; j++) {
                A[i][j] = res1[i][j];
            }
        }
        
        freematrixmemory(3, P);
        freematrixmemory(3, res1);
        delete[] res2;
    }
    
    
}


void solve3by3(double **A, double *b, double *u){
    
    double m;

    
    for (int k=0; k<3; k++) {
        if (A[k][k] == 0) {
            pivot(A, b, k);

        }

        for (int i=k+1; i<3; i++) {
            std::cout << "hello from loop" << "\n";
            m = A[i][k] / A[k][k];
            b[i] = b[i] - m*b[k];
            for (int j=0; j<3; j++) {
                A[i][j] = A[i][j] - m*A[k][j];
            }
        }
        
    }
    std::cout << A[0][0] << " " << A[0][1] << " " << A[0][2] << "\n";
    std::cout << A[1][0] << " " << A[1][1] << " " << A[1][2] << "\n";
    std::cout << A[2][0] << " " << A[2][1] << " " << A[2][2] << "\n";
    
    std::cout << b[0] << "\n";
    std::cout << b[1] << "\n";
    std::cout << b[2] << "\n";
    
    double sum=0;
    
    for (int k=2; k>-1; k--) {
        std::cout << k << "\n";
        if (k==2) {
            u[k] = b[k]/A[k][k];
        }
        else {
            for (int i=k+1; i<=2; i++) {
                std::cout << "hello from loop" << "\n";
                sum += A[k][i]*u[i];
            }
            u[k] = (b[k]-sum) / A[k][k];
            sum = 0;
        }
    }

    
    std::cout << u[2] << "\n";
    std::cout << u[1] << "\n";
    std::cout << u[0] << "\n";
    
    
}
