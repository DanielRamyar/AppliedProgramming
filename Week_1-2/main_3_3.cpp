#include "3_3.h"
#include <iostream>
#include <cassert>

int main(int argc, char* argv[])
{
    int n;
    std::cout << "Enter number of gridpoints\n";
    std::cin >> n;
    assert(n > 1);
    implicit_Euler(n);
    
    return 0;
}
