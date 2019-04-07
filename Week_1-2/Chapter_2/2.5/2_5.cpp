#include <iostream>
#include <cassert>

int main (int argc, char *argv[]) {
    double A[2][2] = {{4.0, 10.0},
                      {1.0, 1.0 }};
    double B[2][2], det, a;
    
    a = A[0][0]*A[1][1] - A[0][1]*A[1][0];
    std::cout << a;
    assert(a != 0.0);
    det = 1 / a;
    
    
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++){
            
            if ((i == 0) && (j == 0)) {
                B[i][j] = det * A[1][1];
            }
            else if ((i == 1) && (j == 1)) {
                B[i][j] = det * A[0][0];
            }
            else {
                B[i][j] = - det * A[i][j];
            }
            
            std::cout << B[i][j] << " " << i << " " << j << "\n";
        }
    }
}
