#include <iostream>

void printer(int* x);

int main(int argc, char* argv[])
{
    int c=10;
    
    std::cout << c << "\n";
    
    printer(&c);
    
    std::cout << c << "\n";
    
    return 0;
}

void printer(int* x){
    *x = 2;
    
}
