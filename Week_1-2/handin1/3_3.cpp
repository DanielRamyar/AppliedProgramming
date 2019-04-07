#include <iostream>
#include <fstream>
#include <cassert>

void implicit_Euler(int n)
{
    if (n > 1) {
        double h;
        
        h = 1.0/n;
        
        std::ofstream write_output("xy.dat");
        assert(write_output.is_open());
        
        double x_0=0.0, y_0=1.0, x_1, y_1;
        write_output << x_0 << "," << y_0 << "\n";
        
        for (int i=0; i<n; i++) {
            x_1 = x_0 + h;
            y_1 = y_0 - h*y_0;
            
            write_output << x_1 << "," << y_1 << "\n";
            
            x_0 = x_1;
            y_0 = y_1;
        }
        
        write_output.close();
    }
    else {
        NULL;
    }
    
}
