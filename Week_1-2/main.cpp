#include "2_6.h"
#include <iostream>

int main(int argc, char* argv[])
{
    double x = 0, epsi=1.0e-8, c;
    
    c = newton_Raphson(x, epsi);
    
    std::cout << c << "\n";
    
    return 0;
}
