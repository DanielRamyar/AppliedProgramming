#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    /* Promps user to enter two integers and ouputs the product of these */
    
    int a, b;
    std::cout << "Enter two integers\n";
    std::cin >> a >> b;
    
    a *= b;
    
    std::cout << "The product is " << a << "\n";
}
