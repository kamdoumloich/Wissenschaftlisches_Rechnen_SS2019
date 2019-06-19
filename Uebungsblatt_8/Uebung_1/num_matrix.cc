#include "num_matrix.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>

// Arithmetic functions 

// Multiplication by value x
template <class T>
NumMatrixClass<T> &NumMatrixClass<T>::operator*=(T x)
{
  for (size_t i=0;i<numRows_*numCols_;++i)
    a_[i]*=x;
      
  return *this;
}

// Addition
template <class T>
NumMatrixClass<T> &NumMatrixClass<T>::operator+=(const NumMatrixClass<T> &x)
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
NumMatrixClass<T> operator*(const NumMatrixClass<T> &a, T x)
{
  NumMatrixClass<T> temp(a);
  temp *= x;
  return temp;
}

template <class T>
NumMatrixClass<T> operator*(T x, const NumMatrixClass<T> &a)
{
  NumMatrixClass<T> temp(a);
  temp *= x;
  return temp;
}

// Concatenate
template <class T>
NumMatrixClass<T> operator+(const NumMatrixClass<T> &a, const NumMatrixClass<T> &b)
{
  MatrixClass<T> temp(a);
  temp += b;
  return temp;
}
