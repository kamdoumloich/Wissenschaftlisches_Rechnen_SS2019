#include "matrix_double.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>

// Set number of matrix rows and columns and 
// initialize matrix elements with a given double value
template <class T>
void MatrixClass<T>::resize(size_t numRows, size_t numCols, const T &value)
{
  if ((numRows+numCols>0) && (numRows*numCols==0)) {
    numRows=0;
    numCols=0;
  }
  a_.release();
  numRows_=numRows;
  numCols_=numCols;
  a_=std::unique_ptr<T[]>(new T[numRows_*numCols_]);
  for (size_t i=0;i<numRows_*numCols_;++i)
    a_[i]=value;
}

// Access matrix element at position (i,j)
template <class T>
T &MatrixClass<T>::operator()(size_t i, size_t j)
{
  if ((i<0)||(i>=numRows_)) {
    std::string err;
    err.append("Illegal row index ");
    err.append(std::to_string(i));
    err.append(" valid range is (0: ");
    err.append(std::to_string(numRows_ - 1));
    err.append(")");
    throw std::out_of_range(err);
    exit(EXIT_FAILURE);
  }
  if ((j<0)||(j>=numCols_))
  {
    std::string err;
    err.append("Illegal column index ");
    err.append(std::to_string(j));
    err.append(" valid range is (0: ");
    err.append(std::to_string(numCols_ - 1));
    err.append(")");
    throw std::out_of_range(err);
    exit(EXIT_FAILURE);
  }
  return a_[i*numCols_+j];
}

// Access matrix element at position (i,j)
template <class T>
T MatrixClass<T>::operator()(size_t i, size_t j) const
{
  if ((i<0)||(i>=numRows_))
  {
    std::string err;
    err.append("Illegal row index ");
    err.append(std::to_string(i));
    err.append(" valid range is (0: ");
    err.append(std::to_string(numRows_ - 1));
    err.append(")");
    throw std::out_of_range(err);
    exit(EXIT_FAILURE);
  }
  if ((j<0)||(j>=numCols_))
  {
    std::string err;
    err.append("Illegal column index ");
    err.append(std::to_string(j));
    err.append(" valid range is (0: ");
    err.append(std::to_string(numCols_ - 1));
    err.append(")");
    throw std::out_of_range(err);
    exit(EXIT_FAILURE);
  }
  return a_[i*numCols_+j];
}

// Output matrix content
template <class T>
void MatrixClass<T>::print() const
{
  std::cout << "(" << numRows_ << "x";
  std::cout << numCols_ << ") matrix:\n";
  for (size_t i=0;i<numRows_;++i) {
    std::cout << std::setprecision(3);
    for (size_t j=0;j<numCols_;++j)
        std::cout << std::setw(5) << a_[i*numCols_+j] << " ";
    std::cout << "\n";
  }
  std::cout << "\n";
}
