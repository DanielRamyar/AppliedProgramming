#ifndef TEST_5_6
#define TEST_5_6

double** allocate_matrix(int row, int col);
void freematrixmemory(int row, double** matrix);

void Multiply(double *res , double *A, double **B, int ACols , int BRows, int BCols) ;
void Multiply(double *res , double **A, double *B, int ARows, int ACols , int BRows) ;

void Multiply(double **res , double scalar , double **B, int BRows, int BCols);
void Multiply(double **res , double **B, double scalar , int BRows, int BCols);

void Multiply(double **res , double **A, double **B, int ARows, int ACols,
                                                     int BRows, int BCols);

#endif
