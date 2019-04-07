#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char* argv[])
{
    int array[5] = {34, 58, 57, 32, 43}, temp;
    double avg;
    
    temp += array[0];
    temp += array[1];
    temp += array[2];
    temp += array[3];
    temp += array[4];
    
    avg = ((double)(temp)) / 5;
    
    std::cout << "The Average is " << avg << "\n";

}
