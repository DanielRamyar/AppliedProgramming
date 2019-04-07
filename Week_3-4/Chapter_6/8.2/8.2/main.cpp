#include <iostream>
#include "Exercise82.hpp"

int main(int argc, const char * argv[]) {
    
    std::cout << "Absolute value is " << CalcAbs<int>(-4) << " and " << CalcAbs<int>(10) << "\n";
    
    std::cout << "Absolute value is " << CalcAbs<double>(-3.3) << " and " << CalcAbs<int>(5.4) << "\n";
    
    return 0;
}
