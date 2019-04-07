#include <iostream>

int main(int argc, char* argv[])
{
    double p, q, x, y; int j;
    
    p = 8.0;
    q = 6.0;
    y = 8.0;
    j = 24;
    
    // Question 1.
//    if ((p >= q) || (j != 10))
//    {
//        x = 5.0;
//    }
    // Question 2.
//    if ((y >= q) && (j == 20))
//    {
//        x = 5.0;
//    }
//    else
//    {
//        x = p;
//    }

    // Question 3.
    if (p > q) {
        x = 0;
    }
    else if ((p <= q) && (j == 10)){
        x = 1;
    }
    else {
        x = 2;
    }
    
    std::cout << x << "\n";
    
    return 0;
}







