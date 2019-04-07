#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF
#include "Vector.hpp"
#include <cmath>
#include <cassert>

template <class T>
class Matrix
{
private:
	std::vector<T> mData; // entries of matrix
	int mNumRows, mNumCols; // dimensions
public:
	Matrix(const Matrix& otherMatrix);
	Matrix(int numRows, int numCols);
//	~Matrix();
	int GetNumberOfRows() const;
	int GetNumberOfColumns() const;
	T& operator()(int i, int j);
	T const& operator()(int i, int j)const;
	//overloaded assignment operator
	Matrix& operator=(const Matrix& otherMatrix);
	Matrix operator-() const; // unary -
	Matrix operator+(const Matrix& m1) const; // binary +
	Matrix operator-(const Matrix& m1) const; // binary -
	// scalar multiplication
	Matrix operator*(double a) const;
    
    // std::vector method from assignment
    std::vector<T> const& getStorage() const;
};
////matrix-vector multiplications
//Vector operator*(const Matrix& m, const Vector& v);
//Vector operator*(const Vector& v, const Matrix& m);
//
//



// Overwritten copy constructor
// Allocate memory for new matrix, and copy
// entries into this matrix
template <class T>
Matrix<T>::Matrix(const Matrix& otherMatrix)
{
	mNumRows = otherMatrix.mNumRows;
	mNumCols = otherMatrix.mNumCols;
//	mData = new T* [mNumRows];
//	for (int i=0; i<mNumRows; i++)
//	{
//		mData[i] = new T [mNumCols];
//	}
//	for (int i=0; i<mNumRows; i++)
//	{
//		for (int j=0; j<mNumCols; j++)
//		{
//			mData[i][j] = otherMatrix.mData[i][j];
//		}
//	}
    
    mData = otherMatrix.mData;
}

// Constructor for vector of a given length
// Allocates memory, and initialises entries
// to zero
template <class T>
Matrix<T>::Matrix(int numRows, int numCols)
{
	assert(numRows > 0);
	assert(numCols > 0);
	mNumRows = numRows;
	mNumCols = numCols;
//	mData = new T* [mNumRows];
//	for (int i=0; i<mNumRows; i++)
//	{
//		mData[i] = new T [mNumCols];
//	}
//	for (int i=0; i<mNumRows; i++)
//	{
//		for (int j=0; j<mNumCols; j++)
//		{
//			mData[i][j] = 0.0;
//		}
//	}
    
    mData = std::vector<T> ((numRows*numCols), 0);
}

//// Overwritten destructor to correctly free memory
//template <class T>
//Matrix<T>::~Matrix()
//{
//	for (int i=0; i<mNumRows; i++)
//	{
//		delete[] mData[i];
//	}
//	delete[] mData;
//}

// Method to get number of rows of matrix
template <class T>
int Matrix<T>::GetNumberOfRows() const
{
	return mNumRows;
}

// Method to get number of columns of matrix
template <class T>
int Matrix<T>::GetNumberOfColumns() const
{
	return mNumCols;
}

// Overloading the round brackets
// Note that this uses `zero-based' indexing,
// and a check on the validity of the index
template <class T>
T& Matrix<T>::operator()(int i, int j)
{
	assert(i >= 0);
	assert(i < mNumRows);
	assert(j >= 0);
	assert(j < mNumCols);
	return mData[i*GetNumberOfColumns() + j];
}
template <class T>
T const& Matrix<T>::operator()(int i, int j) const
{
	assert(i >= 0);
	assert(i < mNumRows);
	assert(j >= 0);
	assert(j < mNumCols);
	return mData[i*GetNumberOfColumns() + j];
}

// Overloading the assignment operator
template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix& otherMatrix)
{
	assert(mNumRows = otherMatrix.mNumRows);
	assert(mNumCols = otherMatrix.mNumCols);

	for (int i=0; i<mNumRows; i++)
	{
		for (int j=0; j<mNumCols; j++)
		{
			mData[i*GetNumberOfColumns() + j] = otherMatrix.mData[i*GetNumberOfColumns() + j];
		}
	}
	return *this;
}

// Overloading the unary - operator
template <class T>
Matrix<T> Matrix<T>::operator-() const
{
	Matrix mat(mNumRows, mNumCols);
	for (int i=0; i<mNumRows; i++)
	{
		for (int j=0; j<mNumCols; j++)
		{
			mat(i,j) = -mData[i*GetNumberOfColumns() + j];
		}
	}
	return mat;
}

// Overloading the binary + operator
template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix& m1) const
{
	assert(mNumRows == m1.mNumRows);
	assert(mNumCols == m1.mNumCols);
	Matrix mat(mNumRows, mNumCols);
	for (int i=0; i<mNumRows; i++)
	{
		for (int j=0; j<mNumCols; j++)
		{
			mat(i,j) = mData[i*GetNumberOfColumns() + j] + m1.mData[i*GetNumberOfColumns() + j];
		}
	}
	return mat;
}

// Overloading the binary - operator
template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix& m1) const
{
   assert(mNumRows == m1.mNumRows);
   assert(mNumCols == m1.mNumCols);
   Matrix mat(mNumRows, mNumCols);
   for (int i=0; i<mNumRows; i++)
   {
      for (int j=0; j<mNumCols; j++)
      {
         mat(i,j) = mData[i*GetNumberOfColumns() + j] - m1.mData[i*GetNumberOfColumns() + j];
      }
   }
   return mat;
}

// Overloading scalar multiplication
template <class T>
Matrix<T> Matrix<T>::operator*(double a) const
{
   Matrix mat(mNumRows, mNumCols);
   for (int i=0; i<mNumRows; i++)
   {
      for (int j=0; j<mNumCols; j++)
      {
         mat(i,j) = a*mData[i*GetNumberOfColumns() + j];
      }
   }
   return mat;
}

// Overloading matrix multiplied by a vector
template <class T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v)
{
	int original_vector_size = v.size();
	assert(m.GetNumberOfColumns() == original_vector_size);
	int new_vector_length = m.GetNumberOfRows();
	Vector<T> new_vector(new_vector_length);

	for (int i=0; i<new_vector_length; i++)
	{
		for (int j=0; j<original_vector_size; j++)
		{
			new_vector[i] += m(i,j)*v[j];
		}
	}

	return new_vector;
}

// Overloading vector multiplied by a matrix
template <class T>
Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m)
{
	int original_vector_size = v.size();
	assert(m.GetNumberOfRows() == original_vector_size);
	int new_vector_length = m.GetNumberOfColumns();
	Vector<T> new_vector(new_vector_length);

	for (int i=0; i<new_vector_length; i++)
	{
		for (int j=0; j<original_vector_size; j++)
		{
			new_vector[i] += v[j]*m(j,i);
		}
	}

	return new_vector;
}

template <class T>
std::vector<T> const& Matrix<T>::getStorage() const
{
    return mData;
}

#endif
