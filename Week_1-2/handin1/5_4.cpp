#include <iostream>
#include <cmath>
#include "5_4.h"


double calc_mean(double a[], int length) {
    double array_sum, mean;
    
    for (int i=0; i<length; i++) {
        array_sum += a[i];
    }
    
    mean = array_sum / length;
    
    return mean;
}

double calc_std(double a[], int length) {
    double array_sum=0, mean, sigma, sigma_sum=0;
    
    for (int i=0; i<length; i++) {
        array_sum += a[i];
    }
    
    mean = array_sum / length;
    
    for (int i=0; i<length; i++) {
        sigma_sum += (a[i]-mean)*(a[i]-mean);
    }
    
    if (length != 1) {
        sigma = sqrt(sigma_sum / (length-1));
        return sigma;
    }
    else {
        return NULL;
    }

}
