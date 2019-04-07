#include <iostream>
#include <fstream>
#include <cassert>
int main(int argc, char* argv[])
{
    int a=3, b=7;
    
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "Swapping values using pointers \n";
    
    int* p_a;
    int* p_b;
    int* p_c;
    
    p_a = &a;
    p_b = &b;
    p_c = new int;
    
    *p_c = *p_a;
    *p_a = *p_b;
    *p_b = *p_c;
    
    delete p_c;
    
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    
    return 0;
}
