#include "matrix.h"

#ifndef _NUMMATRIX_H_
#define _NUMMATRIX_H_

/**
 * Matrix with arithmetic functions 
 */

template<typename T=double>
class NumMatrix : public Matrix<T>
{
    using Matrix<T>::a_;
    using Matrix<T>::numRows_;
    using Matrix<T>::numCols_;
  public:
    // Arithmetic functions 
    NumMatrix &operator*=(T x);
    template<class U>
    NumMatrix<T> &operator+=(const NumMatrix<U> &b);

    NumMatrix &operator+=(const NumMatrix &b);
    
    // Constructors
    NumMatrix(size_t numRows, size_t numCols, const T &value=T()) : Matrix<T>(numRows,numCols,value)
    {}
    
    NumMatrix(size_t numElem) : Matrix<T>(numElem,numElem)
    {}
    
    NumMatrix() = default;

    template<typename U>
    NumMatrix(const Matrix<U> &b) : Matrix<T>(b)
    {}
    
    NumMatrix<T>(const Matrix<T> &b) : Matrix<T>(b)
    {}
};


// Multiplication by value x
template<typename T>
NumMatrix<T> &NumMatrix<T>::operator*=(T x) {
  for (size_t i=0;i<a_.size();++i)
    a_[i]*=x;
      
  return *this;
}

// Addition
template<typename T>
template<typename U>
NumMatrix<T> &NumMatrix<T>::operator+=(const NumMatrix<U> &x) {
#ifndef NDEBUG
  if ((x.rows()!=numRows_)||(x.cols()!=numCols_))
    throw std::out_of_range("Matrix dimensions not matching in addition: first matrix: "+std::to_string(numRows_)+"x"+std::to_string(numCols_)+" second matrix: "+std::to_string(x.rows())+"x"+std::to_string(x.cols()));
#endif
  for (size_t i=0;i<numRows_;++i)
    for (size_t j=0;j<numRows_;++j)
      a_[i*numCols_+numRows_]+=x(i,j);
  return *this;
}

template<typename T>
NumMatrix<T> &NumMatrix<T>::operator+=(const NumMatrix<T> &x) {
#ifndef NDEBUG
  if ((x.numRows_!=numRows_)||(x.numCols_!=numCols_))
    throw std::out_of_range("Matrix dimensions not matching in addition: first matrix: "+std::to_string(numRows_)+"x"+std::to_string(numCols_)+" second matrix: "+std::to_string(x.numRows_)+"x"+std::to_string(x.numCols_));
#endif
  for (size_t i=0;i<a_.size();++i)
    a_[i]+=x.a_[i];
  return *this;
}


// More arithmetic functions
template<typename T>
NumMatrix<T> operator*(NumMatrix<T> a, T x) {
  a *= x;
  return a;
}

template<typename T>
NumMatrix<T> operator*(T x, NumMatrix<T> a) {
  a *= x;
  return a;
}

// Concatenate
template<typename T, typename U>
NumMatrix<T> operator+(NumMatrix<T> a, NumMatrix<U> b) {
  a += b;
  return a;
}

#endif

