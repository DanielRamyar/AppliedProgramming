#include <iostream>

int main(int argc, char* argv[]) {
    double u[3] = {1.0, 2.0, 3.0};
    double v[3] = {6.0, 5.0, 4.0};
    double A[3][3] = {{1.0, 5.0, 0.0},
                      {7.0, 1.0, 2.0},
                      {0.0, 0.0, 1.0}};
    double B[3][3] = {{-2.0, 0.0, 1.0},
                      {1.0, 0.0, 0.0},
                      {4.0, 1.0, 0.0}};
    double w[3];
    for (int i=0; i<3; i++) {
        w[i] = u[i] - 3.0*v[i];
    }
    
    // x = u-v
    double x[3];
    for (int i=0; i<3; i++) {
        x[i] = u[i] - v[i];
    }

    std::cout << x[0] << x[1] << x[2] << "\n";
    
    // y = A*u
    double y[3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            y[i] += A[i][j] * u[j];
            std::cout << y[i] << "\n";
        }
    }
    
    // z = A*u-v
    double z[3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            z[i] += A[i][j] * u[j];
            std::cout << z[i] << "\n";
        }
        z[i] -= v[i];
        std::cout << z[i] << "\n";
    }
    
    // C = 4*A-3*B
    double C[3][3];
    std::cout << "C" << "\n";
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            C[i][j] = 4*A[i][j] - 3*B[i][j];
            std::cout << C[i][j] << " " << i+1 << " " << j+1 << "\n";
        }
    }
    
    // D = A*B
    double D[3][3], temp;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                temp += A[i][k] * B[k][j];
            }
            D[i][j] = temp;
            std::cout << temp << " " << i+1 << " " << j+1 << "\n";
            temp = 0;
        }
    }
    
    
    return 0;
}


















