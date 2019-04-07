#include <iostream>
#include <cmath>

double** allocate_matrix(int row, int col);
void freematrixmemory(int row, double** matrix);
double** Multiply(double** A, double** B, int rows_a, int cols_a,
                                          int rows_b, int cols_b);

int main(int argc, char* argv[])
{
    int rows_a=2, cols_a=2, rows_b=2, cols_b=2;
    
    // Define my matrices
    double **A, **B;
    A = allocate_matrix(rows_a,cols_a);
    B = allocate_matrix(rows_b,cols_b);
    
    // Insert data in matrices
    // A = 1 1   B = 1 2
    //     2 2       2 3
    for (int i=0; i<rows_a; i++) {
        for (int j=0; j<rows_a; j++) {
            A[i][j] = i+1;
            B[i][j] = j+1*i+1;
            std::cout << "Matrix A " << A[i][j] << "\n";
            std::cout << "Matrix B " << B[i][j] << "\n";
        }
    }
    std::cout << "works here" << "\n";
    double** C;
    C = Multiply(A, B, rows_a, cols_a, rows_b, cols_b);
    
    // Deleting arrays
    freematrixmemory(rows_a, A);
    freematrixmemory(rows_a, B);
    freematrixmemory(rows_a, C);
    
    return 0;
}


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

double** Multiply(double** A, double** B, int rows_a, int cols_a,
                                          int rows_b, int cols_b) {
    
    if (rows_a == cols_b) {
        double** result;
        result = allocate_matrix(rows_a,cols_b);
        
        for (int i=0; i<rows_a; i++) {
            for (int j=0; j<cols_b; j++) {
                for (int k=0; k<rows_a; k++) {
                    result[i][j] += A[i][k]*B[k][j];
                }
                std::cout << result[i][j] << "\n";
            }
        }
        return result;
    }
    else {
        return NULL;
    }
    
    
}
