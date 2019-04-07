#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc, char* argv[]) {
    
    double x[4] = {0.0, 1.0, 1.0, 0.0};
    double y[4] = {0.0, 0.0, 1.0, 1.0};
    
    std::ofstream write_output("x_and_y.dat");
    assert(write_output.is_open());
    
    write_output.setf(std::ios::scientific);
    write_output.setf(std::ios::showpos);
    write_output.precision(10);
    
    write_output << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << "\n";
    write_output.flush();
    write_output << y[0] << " " << y[1] << " " << y[2] << " " << y[3] << "\n";
    write_output.flush();
    
    write_output.close();
    return 0;
}
