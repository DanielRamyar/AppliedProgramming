#include <iostream>
#include <cmath>

void mean_dev(double* A, int n);

int main(int argc, char* argv[])
{
    int n;
    n = 10;
    double* array = new double [n];
    
    for (int i=0; i<n; i++) {
        array[i] = i;
    }
    
    mean_dev(array, n);
    delete[] array;
    return 0;
}

void mean_dev(double* A, int n) {
    double array_sum, mean, sigma, sigma_sum;
    
    for (int i=0; i<n; i++) {
        array_sum += A[i];
    }
    
    mean = array_sum / n;
    
    for (int i=0; i<n; i++) {
        sigma_sum += (A[i]-mean)*(A[i]-mean);
    }
    std::cout << "Mean of array is " << sigma_sum << "\n";
    sigma = sqrt(sigma_sum / (n-1));
    
    std::cout << "Mean of array is " << mean << "\n";
    std::cout << "Standard deviation of array is " << sigma << "\n";
}
