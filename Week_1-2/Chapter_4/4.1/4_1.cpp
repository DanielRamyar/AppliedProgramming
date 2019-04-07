#include <iostream>
#include <fstream>
#include <cassert>
int main(int argc, char* argv[])
{
    int i=5;
    int* p_j;
    
    p_j = &i;
    
    std::cout << *p_j*5 << "\n";
    
    int* p_k;
    
    p_k = new int;
    
    *p_k = i;
    
    
    std::cout << *p_k << "\n" ;
    
    delete p_k;
    
    return 0;
}
