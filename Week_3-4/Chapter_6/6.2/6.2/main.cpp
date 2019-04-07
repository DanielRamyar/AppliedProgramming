#include <iostream>
#include "Matrix2x2.hpp"

int main(int argc, const char * argv[]) {
    
    Matrix2x2 A(4, 7, 2, 6);
    
    std::cout << A.Getval00() << " " << A.Getval01() << "\n";
    std::cout << A.Getval10() << " " << A.Getval11() << "\n";
    
    Matrix2x2 B(A.CalcInverse());

    std::cout << B.Getval00() << " " << B.Getval01() << "\n";
    std::cout << B.Getval10() << " " << B.Getval11() << "\n";
    
    Matrix2x2 C;
    
    C = A - B;
    
    std::cout << C.Getval00() << " " << C.Getval01() << "\n";
    std::cout << C.Getval10() << " " << C.Getval11() << "\n";
    
    C.MultScalar(2);
    
    std::cout << C.Getval00() << " " << C.Getval01() << "\n";
    std::cout << C.Getval10() << " " << C.Getval11() << "\n";
    
    return 0;
}
