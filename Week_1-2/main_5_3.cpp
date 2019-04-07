#include "5_3.h"
#include <iostream>

int main(int argc, char* argv[])
{
    double a=10.0, b=6.0;
    
    std::cout << a << " " << b << "\n";
    
    swap_pointer(&a, &b);
    
    std::cout << a << " " << b << "\n";
    
    swap_ref(a, b);
    
    std::cout << a << " " << b << "\n";
    
    return 0;
}
