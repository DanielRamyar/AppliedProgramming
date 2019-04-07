#ifndef H_5_10_H
#define H_5_10_H

void solve3by3(double **A, double *b, double *u);

double** allocate_matrix(int row, int col);
void freematrixmemory(int row, double** matrix);
void pivot(double **A, double *b, int k, int size);


#endif
