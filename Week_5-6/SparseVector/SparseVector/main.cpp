//
//  main.cpp
//  SparseVector
//
//  Created by Daniel Ramyar on 24/05/18.
//  Copyright © 2018 Daniel Ramyar. All rights reserved.
//


#include "SparseVector.hpp"
#include <iostream>
int main(int argc, const char * argv[]) {
    
    
    // Default constructor and size test
    std::cout << "Default constructor and .size() test\n";
    SparseVector<double> x;
    std::cout << "Dimension of vector: " <<  x.size() << "\n";
    
    std::cout << "\n";

    // Specific dimension constructor and getValue test
    std::cout << "Specific dimension constructor and .getValue() test\n";
    SparseVector<double> y(10);
    std::cout << "Dimension of vector: " <<  y.size() << "\n";
    std::cout << "Get value index 2: " <<  y.getValue(2) << "\n";
    
    std::cout << "\n";
    
    // .setValue() test
    std::cout << ".setValue() test\n";
    y.setValue(3, 4);
    y.setValue(4, 3.2);
    y.setValue(0, 2.1);
    
    y.print_whole_vector();
    
    std::cout << "\n";
    
    // .nonZero() test
    std::cout << ".nonZero() test\n";
    y.setValue(10, 12.2);
    std::cout << "Number of Non Zero entries: " << y.nonZeroes() << "\n";
    y.print_whole_vector();
    
    std::cout << "\n";
    
    // .indexNonZero() test
    std::cout << ".indexNonZero() test\n";
    unsigned int n = 2;
    std::cout << "Index of " << n+1 << ". non zero entry is: " << y.indexNonZero(n) << "\n";
    
    std::cout << "\n";
    
    // .valueNonZero() test
    std::cout << ".valueNonZero() test\n";
    std::cout << "Value of " << n+1 << ". non zero entry is: " << y.valueNonZero(n) << "\n";
    
    std::cout << "\n";
    
    // += test
    x.setValue(10, 4);
    x.setValue(5, 3.3333);
    x.setValue(0, 31.3333);
    std::cout << "+= test\n";
    y += x;
    y.print_whole_vector();
    
    std::cout << "\n";
    
    // -= test
    std::cout << "-= test\n";
    y -= x;
    y.print_whole_vector();
    
    std::cout << "\n";
    
    // binary + test
    std::cout << "Binary + test\n";
    SparseVector<double> z(10);
    z = x+y;
    z.print_whole_vector();
    
    std::cout << "\n";
    
    // binary - test
    std::cout << "Binary - test\n";
    SparseVector<double> k(10);
    k = z-x;
    k.print_whole_vector();
    
    std::cout << "\n";
    
    // Matrix sparsevector multiplication
    Matrix<double> A(4, 4);
    Vector<double> V(4);
    SparseVector<double> S(4);
    
    S.setValue(1, 3.2);
    S.setValue(3, 5.7);
    
    S.print_whole_vector();
    
    A(0,0) = 1; A(0,1) = 2; A(0,2) = 7; A(0,3) = 3;
    A(1,0) = 3; A(1,1) = 6; A(1,2) = 3; A(1,3) = 8;
    A(2,0) = 7; A(2,1) = 4; A(2,2) = 1; A(2,3) = 2;
    A(3,0) = 4.7; A(3,1) = 3.2; A(3,2) = 1; A(3,3) = 2;
    
    std::cout << A(0,0) << " " << A(0,1) << " " << A(0,2) << " " << A(0,3) << "\n"
              << A(1,0) << " " << A(1,1) << " " << A(1,2) << " " << A(1,3) << "\n"
              << A(2,0) << " " << A(2,1) << " " << A(2,2) << " " << A(2,3) << "\n"
              << A(3,0) << " " << A(3,1) << " " << A(3,2) << " " << A(3,3) << "\n";
    
    V = A*S;
    
    std::cout << V[0] << "\n" << V[1] << "\n" << V[2] << "\n"<< V[3] << "\n";
    
    // Sparsevector Matrix multiplication
    Matrix<double> B(4, 4);
    Vector<double> V1(4);
    SparseVector<double> S1(4);
    
    //S1.setValue(1, 3.2);
    S1.setValue(3, 5.7);
    
    S1.print_whole_vector();
    
    B(0,0) = 1; B(0,1) = 2; B(0,2) = 7; B(0,3) = 3;
    B(1,0) = 3; B(1,1) = 6; B(1,2) = 3; B(1,3) = 8;
    B(2,0) = 7; B(2,1) = 4; B(2,2) = 1; B(2,3) = 2;
    B(3,0) = 4.7; B(3,1) = 3.2; B(3,2) = 1; B(3,3) = 2;
    
    std::cout << B(0,0) << " " << B(0,1) << " " << B(0,2) << " " << B(0,3) << "\n"
              << B(1,0) << " " << B(1,1) << " " << B(1,2) << " " << B(1,3) << "\n"
              << B(2,0) << " " << B(2,1) << " " << B(2,2) << " " << B(2,3) << "\n"
              << B(3,0) << " " << B(3,1) << " " << B(3,2) << " " << B(3,3) << "\n";
    
    V1 = S1*B;
    
    std::cout << V1[0] << "\n" << V1[1] << "\n" << V1[2] << "\n"<< V1[3] << "\n";
    
    
    return 0;
}
