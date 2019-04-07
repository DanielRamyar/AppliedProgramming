#include "5_10.h"
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

void pivot(double **A, double *b, int k, int size) {
    
    double max=A[k][k];
    int temp=k;
    for (int n=k+1; n<size; n++){
        if (A[n][k] > max) {
            max = A[n][k];
            temp = n;
        }
        else {
            NULL;
        }
    }
    
    if (temp != k){
        double** P=allocate_matrix(size,size);
        int n=temp;
        
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                if ((i==j) && (i!=k) && (j!=k) && (i!=n) && (j!=n)){
                    P[i][j] = 1.0;
                }
                else if ((i==k) && (j==n)){
                    P[i][j] = 1.0;
                }
                else if ((i==n) && (j==k)){
                    P[i][j] = 1.0;
                }
                else{
                    P[i][j] = 0.0;
                }
            }
        }
        
        double tempo=0.0;
        double** res1=allocate_matrix(size,size);
        
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                for (int k=0; k<size; k++) {
                    tempo += P[i][k]*A[k][j];
                }
                res1[i][j] = tempo;
                tempo = 0;
            }
        }
        
        double *res2= new double [size];
        tempo = 0.0;
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                tempo += P[i][j]*b[j];
            }
            res2[i] = tempo;
            tempo = 0.0;
        }
        
        for (int i=0; i<size; i++) {
            b[i] = res2[i];
            for (int j=0; j<size; j++) {
                A[i][j] = res1[i][j];
            }
        }
        
        freematrixmemory(size, P);
        freematrixmemory(size, res1);
        delete[] res2;
    }
    
    
}


void guassian_elimination(double **A, double *b, double *u, int n){
    
    double m;

    
    for (int k=0; k<n; k++) {
        pivot(A, b, k, n);
        

        for (int i=k+1; i<n; i++) {
            m = A[i][k] / A[k][k];
            b[i] = b[i] - m*b[k];
            for (int j=0; j<n; j++) {
                A[i][j] = A[i][j] - m*A[k][j];
            }
        }
        
    }
    

    
    double sum=0;
    
    for (int k=n-1; k>-1; k--) {
        if (k==(n-1)) {
            u[k] = b[k]/A[k][k];
        }
        else {
            for (int i=k+1; i<=n-1; i++) {
                sum += A[k][i]*u[i];
            }
            u[k] = (b[k]-sum) / A[k][k];
            sum = 0;
        }
    }


    
    
}
