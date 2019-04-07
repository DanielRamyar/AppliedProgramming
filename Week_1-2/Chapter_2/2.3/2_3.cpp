#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
    int x = 0;
    double a=0.0, b=0.0;
    while (x != 1) {
        std::cout << "Enter number (write -1 to end or -2 to reset):\n";
        std::cin >> a;
        if ((fabs(a+1) < 1.0e-8) || (b > 100)) {
            x = 1;
        }
        else if (fabs(a+2) < 1.0e-8){
            b = 0;
            std::cout << "sum is reset\n";
        }
        else {
            b += a;
        }
        
    }
    std::cout << "The sum is " << b << "\n";
    return 0;
}
