#include "ComplexNumber.hpp"
#include "CalculateExponential.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    ComplexNumber z1(4.0, 3.0);

    std::cout << "z1 = " << z1 << "\n";
    std::cout << "Modulus z1 = "
              << z1.CalculateModulus() << "\n";
    std::cout << "Argument z1 = "
              << z1.CalculateArgument() << "\n";


    ComplexNumber z2;
    z2 = z1.CalculatePower(3);
    std::cout << "z2 = z1*z1*z1 = " << z2 << "\n";

    ComplexNumber z3;
    z3 = -z2;
    std::cout << "z3 = -z2 = " << z3 << "\n";
    
    ComplexNumber z4;
    z4=z1+z2;
    std::cout << "z1 + z2 = "<< z4 << "\n";
    
    ComplexNumber zs[2];
    zs[0] = z1;
    zs[1] = z2;
    std::cout << "Second element of zs = "
              << zs[1] << "\n";
    
    /* Exercises */
    // 6.1.1
    std::cout << "Real part of z3 = " << z3.GetRealPart() << "\n";
    std::cout << "Imaginary part of z3 = " << z3.GetImaginaryPart() << "\n";
    
    // 6.1.2
    std::cout << "Real part of z3 = " << RealPart(z3) << "\n";
    std::cout << "Imaginary part of z3 = " << ImaginaryPart(z3) << "\n";
    
    // 6.1.3
    ComplexNumber z_copy(z1);
    std::cout << "z_copy = " << z_copy << "\n";
    
    // 6.1.4
    ComplexNumber z_real(5.5);
    std::cout << "z_real = " << z_real << "\n";
    
    
    // 6.1.5
    std::cout << "Complex Conjugate of z1 = " << z1.CalculateConjugate() << "\n";
    
    // 6.1.6
    z1.SetConjugate();
    std::cout << "Complex Conjugate of z1 = " << z1 << "\n";
    
    // 6.1.7
    int n=3;
    ComplexNumber** A = AllocateMatrix(n, n);
    ComplexNumber** res = AllocateMatrix(n, n);
    ComplexNumber test1(2,3), test2(0,0), test3(0,0);
    ComplexNumber test4(0,0), test5(4,5), test6(0,0);
    ComplexNumber test7(0,0), test8(0,0), test9(6,7);
    
    A[0][0] = test1; A[0][1] = test2; A[0][2] = test3;
    A[1][0] = test4; A[1][1] = test5; A[1][2] = test6;
    A[2][0] = test7; A[2][1] = test8; A[2][2] = test9;
    
    CalculateExponential(A, 50, res);
    
    std::cout << "Result\n";
    printMatrix(res, n, n);
    
    std::cout << "My matrix\n";
    printMatrix(A, n, n);

    return 0;
}
