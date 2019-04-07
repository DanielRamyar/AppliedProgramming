#include <iostream>
#include <cmath>
#include "2_6.h"

double newton_Raphson(double initialGuess, double epsilon) {

    double x_0 = initialGuess, x_1, z;
    
    do {
        x_1 = x_0 - (exp(x_0) + x_0*x_0*x_0 - 5) / (exp(x_0) + 3*x_0*x_0);
//        std::cout << x_1 << "\n";
        z = fabs(x_1-x_0);
        x_0 = x_1;
    } while (z > epsilon);
    
    return x_1;

}
