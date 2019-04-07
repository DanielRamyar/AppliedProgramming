#include <iostream>
#include <cmath>

// Part 1-4
//int main (int argc, char *argv[]) {
//    
//    double x_0 = 0.0, x_1;
//    
//    for (int i=0; i<100; i++) {
//        
//        x_1 = x_0 - (exp(x_0) + x_0*x_0*x_0 - 5) / (exp(x_0) + 3*x_0*x_0);
//        std::cout << x_1 << "\n";
//        if (fabs(x_1-x_0) < 1.0e-8){
//            break;
//        }
//        x_0 = x_1;
//    }
//    
//}

// 5.
int main (int argc, char *argv[]) {

    double x_0 = 0.0, x_1, z, epsilon = 1.0e-8;
    
    do {
        x_1 = x_0 - (exp(x_0) + x_0*x_0*x_0 - 5) / (exp(x_0) + 3*x_0*x_0);
        std::cout << x_1 << "\n";
        z = fabs(x_1-x_0);
        x_0 = x_1;
    } while (z > epsilon);

}
