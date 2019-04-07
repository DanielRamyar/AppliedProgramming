#include <iostream>
#include <cmath>
#include "5_6.h"


void Multiply(double *res , double *A, double **B, int ACols , int BRows, int BCols) {
    
    if (ACols == BRows) {
        double temp = 0;
        for (int i=0; i<ACols; i++) {
            for (int j=0; j<BRows; j++) {
                 temp += A[j]*B[j][i];
            }
            res[i] = temp;
            temp = 0;
        }
    }
    else {
        NULL;
    }
}

void Multiply(double *res , double **A, double *B, int ARows, int ACols , int BRows) {
    
    if (ACols == BRows) {
        double temp = 0;
        for (int i=0; i<ARows; i++) {
            for (int j=0; j<BRows; j++) {
                temp += A[i][j]*B[j];
            }
            res[i] = temp;
            temp = 0;
        }
    }
    else {
        NULL;
    }
}

void Multiply(double **res , double scalar , double **B, int BRows, int BCols) {
    
    for (int i=0; i<BRows; i++) {
        for (int j=0; j<BCols; j++) {
            
            res[i][j] = scalar * B[i][j];
        }
    }
}

void Multiply(double **res , double **B, double scalar , int BRows, int BCols) {
    for (int i=0; i<BRows; i++) {
        for (int j=0; j<BCols; j++) {
            
            res[i][j] = B[i][j] * scalar;
        }
    }
}

void Multiply(double **res , double **A, double **B, int ARows, int ACols,
                                                     int BRows, int BCols) {
    
    if (ACols == BRows) {
        double temp=0;
        
        for (int i=0; i<ARows; i++) {
            for (int j=0; j<BCols; j++) {
                for (int k=0; k<ACols; k++) {
                    temp += A[i][k]*B[k][j];
                }
                res[i][j] = temp;
                temp = 0;
            }
        }
    }
    else {
        NULL;
    }
}
