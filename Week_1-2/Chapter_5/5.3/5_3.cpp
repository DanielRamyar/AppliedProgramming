#include <iostream>

void swap_with_pointers(double* x, double* y);
void swap_with_reference(double& x, double& y);

int main(int argc, char* argv[])
{
    double a=10.0, b=6.0;
    
    std::cout << a << " " << b << "\n";
    
    swap_with_pointers(&a, &b);
    
    std::cout << a << " " << b << "\n";
    
    swap_with_reference(a, b);

    std::cout << a << " " << b << "\n";
    
    return 0;
}

void swap_with_pointers(double* x, double* y){
    double temp;
    
    temp = *x;
    
    *x = *y;
    
    *y = temp;
    
}

void swap_with_reference(double& x, double& y){
    double temp;
    
    temp = x;
    
    x = y;
    
    y= temp;
    
}

