#ifndef H_5_10_H
#define H_5_10_H

void guassian_elimination(double **A, double *b, double *u, int n);

double** allocate_matrix(int row, int col);
void freematrixmemory(int row, double** matrix);
void pivot(double **A, double *b, int k);

#endif
