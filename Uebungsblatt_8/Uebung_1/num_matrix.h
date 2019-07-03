#ifndef NUMMATRIXCLASS_H
#define NUMMATRIXCLASS_H

#include <memory>
#include "matrix_double.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>

/**
 * Matrix Class representing matrices of double values
 */

template <class T, typename U = typename std::enable_if<std::is_arithmetic<T>::value>::type>
class NumMatrixClass : public MatrixClass<T>
{
  public:
    
    // Arithmetic functions 
    NumMatrixClass<T> &operator*=(T x);
    NumMatrixClass<T> &operator+=(const NumMatrixClass<T> &b);
    NumMatrixClass<T>& operator=(const NumMatrixClass<T>& b);
    
    
    // Constructors
    NumMatrixClass(size_t numRows, size_t numCols, const T& value=T()) :
      MatrixClass<T>::MatrixClass(numRows, numCols, value) {}
    
    NumMatrixClass(size_t numElem) : MatrixClass<T>::MatrixClass(numElem)
    {}
    
    NumMatrixClass() = default;

    NumMatrixClass(const NumMatrixClass<T> &b)
    {
      numRows_=b.numRows_;
      numCols_=b.numCols_;
      a_=std::unique_ptr<T[]>(new T[numRows_*numCols_]);
      for (size_t i=0;i<numRows_*numCols_;++i)
        a_[i]=b.a_[i];
    }
    
  private:
   // matrix elements
   std::unique_ptr<T[]> a_;
   // number of rows
   size_t numRows_=0;
   // number of columns
   size_t numCols_=0;
};

// More arithmetic functions
template <class T>
NumMatrixClass<T> operator*(const NumMatrixClass<T> &a, T x);
template <class T>
NumMatrixClass<T> operator*(T x, const NumMatrixClass<T> &a);
template <class T>
NumMatrixClass<T> operator+(const NumMatrixClass<T> &a, const NumMatrixClass<T> &b);

// Arithmetic functions 

// Multiplication by value x
template <class T, typename U>
NumMatrixClass<T> &NumMatrixClass<T, U>::operator*=(T x)
{
  for (size_t i=0;i<numRows_*numCols_;++i)
    a_[i]*=x;
      
  return *this;
}

// Addition
template <class T, typename U>
NumMatrixClass<T> &NumMatrixClass<T, U>::operator+=(const NumMatrixClass<T> &x)
{
  if ((x.numRows_!=numRows_)||(x.numCols_!=numCols_)) 
  {
    std::string err;
    err.append("Dimensions of matrix a (");
    err.append(std::to_string(numRows_));
    err.append(" x ");
    err.append(std::to_string(numCols_));
    err.append(") and matrix x (");
    err.append(std::to_string(numRows_));
    err.append(" x ");
    err.append(std::to_string(numCols_));
    err.append(") do not match!");
    throw std::out_of_range(err);
    exit(EXIT_FAILURE);
  }
  for (size_t i=0;i<numRows_*numCols_;++i)
    a_[i]+=x.a_[i];
  return *this;
}


// More arithmetic functions
template <class T>
MatrixClass<T> operator*(const MatrixClass<T> &a, T x)
{
  MatrixClass<T> temp(a);
  temp *= x;
  return temp;
}

template <class T>
MatrixClass<T> operator*(T x, const MatrixClass<T> &a)
{
  MatrixClass<T> temp(a);
  temp *= x;
  return temp;
}

// Concatenate
template <class T>
MatrixClass<T> operator+(const MatrixClass<T> &a, const MatrixClass<T> &b)
{
  MatrixClass<T> temp(a);
  temp += b;
  return temp;
}

#endif