#include "ComplexNumber.hpp"
#include "CalculateExponential.hpp"
#include <cmath>
#include <cassert>

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res)
{
    
    int size = 3;
    
    for (int n=0; n<nMax+1; n++) {
        ComplexNumber temp;
        ComplexNumber** res1=AllocateMatrix(size,size);
        ComplexNumber** res2=AllocateMatrix(size,size);
        
        // Ensures Identity matrix at n=0
        if (n == 0) {
            
            for (int i=0; i<size; i++) {
                for (int j=0; j<size; j++) {
                    if (i==j){
                        res[i][j] = 1;
                    }
                    else {
                        res[i][j] = 0;
                    }
                }
            }
        }
        else if (n == 1) {
            
            for (int i=0; i<size; i++) {
                for (int j=0; j<size; j++) {
                    res[i][j] = res[i][j] + A[i][j];
                }
            }
        }
        
        else {
            // This for loop finds the n'th power of a complex matrix
            for (int q=0; q<n-1; q++) {
                if (q==0) {
                    for (int i=0; i<size; i++) {
                        for (int j=0; j<size; j++) {
                            for (int k=0; k<size; k++) {
                                temp = temp + A[i][k]*A[k][j];
                            }
                            res1[i][j] = temp / (q+2);
                            temp.ResetComplexNumber();
                        }
                    }
                }
                
                else {
                    for (int i=0; i<size; i++) {
                        for (int j=0; j<size; j++) {
                            for (int k=0; k<size; k++) {
                                temp = temp + res1[i][k]*A[k][j];
                            }
                            res2[i][j] = temp / (q+2);
                            temp.ResetComplexNumber();
                        }
                    }

                    for (int i=0; i<size; i++) {
                        for (int j=0; j<size; j++) {
                            res1[i][j] = res2[i][j];
                        }
                    }
                }
                
                
            }
            
            for (int i=0; i<size; i++) {
                for (int j=0; j<size; j++) {
                    res[i][j] = res[i][j] + res1[i][j] ;
                }
            }
        }
        FreeMatrixMemory(size, res1);
        FreeMatrixMemory(size, res2);
    }
    
}


void printMatrix(ComplexNumber **A, int rows, int cols)
{
    for (int i=0; i<rows; i++) {
        std::cout << "| ";
        for (int j=0; j<cols; j++) {
            std::cout << " " << A[i][j];
        }
        std::cout << " |\n";
    }
}
