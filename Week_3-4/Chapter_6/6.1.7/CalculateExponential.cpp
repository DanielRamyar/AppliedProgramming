#include "ComplexNumber.hpp"
#include "CalculateExponential.hpp"
#include <cmath>

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res)
{
    int size = 2;
    ComplexNumber temp;
    ComplexNumber** res1=AllocateMatrix(2,2);
    ComplexNumber** res2=AllocateMatrix(2,2);
    
    for (int q=0; q<nMax-1; q++) {
        
        if (q==0) {
            for (int i=0; i<size; i++) {
                for (int j=0; j<size; j++) {
                    for (int k=0; k<size; k++) {
                        temp = temp + A[i][k]*A[k][j];
                    }
                    res1[i][j] = temp;
                    temp.ResetComplexNumber();
                }
            }
        }
        else {
            for (int i=0; i<size; i++) {
                for (int j=0; j<size; j++) {
                    for (int k=0; k<size; k++) {
                        std::cout << "loop2" << temp << " " << j << "\n";
                        std::cout << "loop2" << res1[i][k] << " " << A[k][j] << "\n";
                        temp = temp + res1[i][k]*A[k][j];
                        std::cout << "loop2" << temp << "\n";
                    }
                    res2[i][j] = temp;
                    temp.ResetComplexNumber();
                }
            }
        }
    }
    std::cout << res2[0][0] << " " << res2[0][1] << "\n";
    std::cout << res2[1][0] << " " << res2[1][1] << "\n";
    
}
