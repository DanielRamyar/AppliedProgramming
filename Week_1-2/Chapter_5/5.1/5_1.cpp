#include <iostream>

void printer(int& x);

int main(int argc, char* argv[])
{
    int c=10;
    
    printer(c);
    
    return 0;
}

void printer(int& x){
    std::cout << x << "\n";
}
