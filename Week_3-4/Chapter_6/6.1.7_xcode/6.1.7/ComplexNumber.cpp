#include "ComplexNumber.hpp"
#include <cmath>

// Override default constructor
// Set real and imaginary parts to zero
ComplexNumber::ComplexNumber()
{
    mRealPart = 0.0;
    mImaginaryPart = 0.0;
}

// Constructor that sets complex number z=x+iy
ComplexNumber::ComplexNumber(double x, double y)
{
    mRealPart = x;
    mImaginaryPart = y;
}

// Method for computing the modulus of a
// complex number
double ComplexNumber::CalculateModulus() const
{
    return sqrt(mRealPart*mRealPart+
                mImaginaryPart*mImaginaryPart);
}

// Method for computing the argument of a
// complex number
double ComplexNumber::CalculateArgument() const
{
    return atan2(mImaginaryPart, mRealPart);
}

// Method for raising complex number to the power n
// using De Moivre’s theorem - first complex
// number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
    double modulus = CalculateModulus();
    double argument = CalculateArgument();
    double mod_of_result = pow(modulus, n);
    double arg_of_result = argument*n;
    double real_part = mod_of_result*cos(arg_of_result);
    double imag_part = mod_of_result*sin(arg_of_result);
    ComplexNumber z(real_part, imag_part);
    return z;
}

// Overloading the = (assignment) operator
ComplexNumber& ComplexNumber::
               operator=(const ComplexNumber& z)
{
    mRealPart = z.mRealPart;
    mImaginaryPart = z.mImaginaryPart;
    return *this;
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const
{
    ComplexNumber w;
    w.mRealPart = -mRealPart;
    w.mImaginaryPart = -mImaginaryPart;
    return w;
}

// Overloading the binary + operator
ComplexNumber ComplexNumber::
              operator+(const ComplexNumber& z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart + z.mRealPart;
    w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
    return w;
}

// Overloading the binary - operator
ComplexNumber ComplexNumber::
              operator-(const ComplexNumber& z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart - z.mRealPart;
    w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart;
    return w;
}

// Overloading the insertion << operator
std::ostream& operator<<(std::ostream& output,
                         const ComplexNumber& z)
{
    // Format as "(a + bi)" or as "(a - bi)"
    output << "(" << z.mRealPart << " " ;
    if (z.mImaginaryPart >= 0.0)
    {
        output << "+ " << z.mImaginaryPart << "i)";
    }
    else
    {
        // z.mImaginaryPart < 0.0
        // Replace + with minus sign
        output << "- " << -z.mImaginaryPart << "i)";
    }
    
    return output;
}


/* Exercises */

// 6.1.1
// Method for returning private members

double ComplexNumber::GetRealPart() const
{
    return mRealPart;
}


double ComplexNumber::GetImaginaryPart() const
{
    return mImaginaryPart;
}

// 6.1.2
// Friend function to return private members
double RealPart(const ComplexNumber& z)
{
    return z.mRealPart;
}

double ImaginaryPart(const ComplexNumber& z)
{
    return z.mImaginaryPart;
}

// 6.1.3
// Overloaded copy contructor;
ComplexNumber::ComplexNumber(const ComplexNumber& z)
{
    mRealPart = z.mRealPart;
    mImaginaryPart = z.mImaginaryPart;
}

// 6.1.4
// Takes a real number and return a complex number where imaginary part is zero.
ComplexNumber::ComplexNumber(double real)
{
    mRealPart = real;
    mImaginaryPart = 0.0;
}

// 6.1.5
// Return the conjugate of a complex number without changing the original
ComplexNumber ComplexNumber::CalculateConjugate() const
{
    ComplexNumber z(mRealPart, -mImaginaryPart);
    return z;
}

// 6.1.6
// Changes the value of the object to complex conjugate
void ComplexNumber::SetConjugate()
{
    mImaginaryPart = -mImaginaryPart;
}

// 6.1.7
//

ComplexNumber ComplexNumber::
              operator*(const ComplexNumber& z) const
{
    ComplexNumber x;
    x.mRealPart = mRealPart*z.mRealPart + mImaginaryPart*z.mImaginaryPart*(-1);
    x.mImaginaryPart = mRealPart*z.mImaginaryPart + z.mRealPart*mImaginaryPart;
    return x;
}

ComplexNumber ComplexNumber::
              operator/(const int& z) const
{
    ComplexNumber x;
    x.mRealPart = mRealPart / z;
    x.mImaginaryPart = mImaginaryPart / z;
    return x;
}


void ComplexNumber::ResetComplexNumber()
{
    mRealPart = 0.0;
    mImaginaryPart = 0.0;
}



ComplexNumber** AllocateMatrix(int row, int col)
{
    ComplexNumber** matrix = new ComplexNumber* [row];
    
    for (int i=0; i<row; i++) {
        matrix[i] = new ComplexNumber [col];
    }
    return matrix;
}

void FreeMatrixMemory(int row, ComplexNumber** matrix)
{
    for (int i=0; i<row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

