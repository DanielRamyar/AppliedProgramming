#include "5_4.h"
#include <iostream>

int main(int argc, char* argv[])
{
    int n;
    n = 10;
    double* array = new double [n];
    
    for (int i=0; i<n; i++) {
        array[i] = i;
    }
    double mean, sigma;
    mean = calc_mean(array, n);
    sigma = calc_std(array, n);
    
    std::cout << "Mean of array is " << mean << "\n";
    std::cout << "Standard deviation of array is " << sigma << "\n";
    
    delete[] array;
    
    return 0;
}
