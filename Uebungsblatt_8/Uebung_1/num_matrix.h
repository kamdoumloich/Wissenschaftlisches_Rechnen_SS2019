#ifndef NUMMATRIXCLASS_H
#define NUMMATRIXCLASS_H

#include <memory>
#include "matrix_double.h"

/**
 * Matrix Class representing matrices of double values
 */

template <class T>
class NumMatrixClass : public MatrixClass<T>
{
  public:
    
    // Arithmetic functions 
    NumMatrixClass<T> &operator*=(T x);
    NumMatrixClass<T> &operator+=(const NumMatrixClass<T> &b);
    
    NumMatrixClass<T>& operator=(const NumMatrixClass<T>& b)
    {
      a_.release();
      numRows_=b.numRows_;
      numCols_=b.numCols_;
      a_=std::unique_ptr<T[]>(new T[numRows_*numCols_]);
      for (size_t i=0;i<numRows_*numCols_;++i)
        a_[i]=b.a_[i];
      return *this;
    }
    
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

#endif