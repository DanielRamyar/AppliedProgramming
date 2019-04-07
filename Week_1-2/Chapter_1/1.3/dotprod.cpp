#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char* argv[])
{
    /* Defines two vectors and calculates the dot product and norm (distance between them) */
    double array1[3] = {3.0, 2.0, 7.0}, array2[3] = {2.0, 4.0, 6.0};
    
    
    array1[0] *= array2[0];
    array1[1] *= array2[1];
    array1[2] *= array2[2];
    
    std::cout << "Dot Product\n" << array1[0] << "\n" << array1[1] << "\n" << array1[2] << "\n";
    
    double array3[3] = {3.0, 2.0, 7.0}, array4[3] = {2.0, 4.0, 6.0}, norm;
    
    array3[0] -= array4[0];
    array3[1] -= array4[1];
    array3[2] -= array4[2];
    
    
    norm = sqrt(array3[0]*array3[0] + array3[1]*array3[1] + array3[2]*array3[2] );
    
    std::cout << "Norm\n" << norm << "\n";


}
