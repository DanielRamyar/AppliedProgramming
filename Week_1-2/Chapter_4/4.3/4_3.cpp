#include <iostream>
#include <fstream>
#include <cassert>
int main(int argc, char* argv[])
{
    for (int j=0; j<1000000000; j++){
        double* x;
        double* y;

        x = new double [3];
        y = new double [3];

        for (int i=0; i<3; i++) {
            x[i] = ((double)(i));
            y[i] = 2.0*x[i];
        }

        double dot=0;
        for (int i=0; i<3; i++) {
            dot += x[i]*y[i];
        }

//        std::cout << dot << "\n";

        delete[] x;
        delete[] y;
    }
    std::cout << "Done" << "\n";
    return 0;
}
