#include "Matrix2x2.hpp"
#include <cassert>

// Overidden default constructor
Matrix2x2::Matrix2x2()
{
    val00 = 0.0; val01 = 0.0;
    val10 = 0.0; val11 = 0.0;
}

// Overidden copy constructor
Matrix2x2::Matrix2x2(const Matrix2x2 &other)
{
    val00 = other.Getval00(); val01 = other.Getval01();
    val10 = other.Getval10(); val11 = other.Getval11();
}

// Constructor that let you specify matrix elements
Matrix2x2::Matrix2x2(double a, double b, double c, double d)
{
    val00 = a; val01 = b;
    val10 = c; val11 = d;
}

// Returns the determinant of matrix
double Matrix2x2::CalcDeterminant() const
{
    return (val00*val11 - val10*val01);
}

// Return the inverse of matrix
Matrix2x2 Matrix2x2::CalcInverse() const
{
    double det = CalcDeterminant();
    assert(det != 0);
    
    Matrix2x2 inverse(Getval11()/det, -Getval01()/det, -Getval10()/det, Getval00()/det);
    
    return inverse;
}

// Overloading the assignment operator
Matrix2x2& Matrix2x2::
           operator=(const Matrix2x2& z)
{
    val00 = z.Getval00(); val01 = z.Getval01();
    val10 = z.Getval10(); val11 = z.Getval11();
    
    return *this;
}

// Overloading the unary subtraction operator
Matrix2x2 Matrix2x2::
          operator-() const
{
    Matrix2x2 neg;
    
    neg.val00 = -val00; neg.val01 = -val01;
    neg.val10 = -val10; neg.val11 = -val11;
    
    return neg;
}

// Overloading the binary addition operator
Matrix2x2 Matrix2x2::
          operator+(const Matrix2x2& z) const
{
    Matrix2x2 sum;
    
    sum.val00 = val00 + z.val00; sum.val01 = val01 + z.val01;
    sum.val10 = val10 + z.val10; sum.val11 = val11 + z.val11;
    
    return sum;
}

// Overloading the binary subtraction operator
Matrix2x2 Matrix2x2::
          operator-(const Matrix2x2& z) const
{
    Matrix2x2 sub;
    
    sub.val00 = val00 - z.val00; sub.val01 = val01 - z.val01;
    sub.val10 = val10 - z.val10; sub.val11 = val11 - z.val11;
    
    return sub;
}

// Method for multiplying a matrix with a scalar
void Matrix2x2::MultScalar(double scalar)
{
    val00 = val00*scalar; val01 = val01*scalar;
    val10 = val10*scalar; val11 = val11*scalar;
}
