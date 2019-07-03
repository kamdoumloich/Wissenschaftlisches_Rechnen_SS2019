#include <iomanip>
#include <iostream>
#include <vector>
#include <exception>

#ifndef _MATRIX_H_
#define _MATRIX_H_

/**
 * templated matrix 
 */

template<typename T=double>
class Matrix
{
  public:   
    using value_type = T;
    using range_type = size_t;

    class matrix_error : public std::exception
    {};
    
    // set number of matrix rows and columns and initialize its elements with value
    void resize(size_t numRows, size_t numCols, const T& value = T() );
    
    // access matrix element at position (i,j)
    T& operator()(size_t i, size_t j);
    const T& operator()(size_t i, size_t j) const;
    
    // returns number of matrix raws
    size_t rows() const {
      return numRows_;
    }
    
    // returns number of matrix columns
    size_t cols() const {
      return numCols_;
    }
    
    // assigment operators
    Matrix &operator=(const Matrix &b) = default;
    
    template<typename U>
    Matrix<T> &operator=(const Matrix<U> &b) {
      numRows_=b.rows();
      numCols_=b.cols();
      a_.resize(numRows_*numCols_);
      for (size_t i=0;i<numRows_;++i)
        for (size_t j=0;j<numCols_;++j)
          a_[i*numCols_+j]=b(i,j);
    }
    
    // constructors
    Matrix(size_t numRows, size_t numCols, const T &value=T()) :
      numRows_(numRows), numCols_(numCols)
    {      
      if ((numRows_+numCols_>0) && (numRows_*numCols_==0))
        throw std::out_of_range("Illegal matrix dimensions " + std::to_string(numRows) + " " + std::to_string(numCols) );
      a_.resize(numRows_*numCols_,value);
    }
    
    Matrix(size_t numElem) : Matrix(numElem,numElem)
    {}
    
    Matrix() = default;
    
    Matrix(const Matrix &b) = default;
    
    template<typename U>
    Matrix(const Matrix<U> &b) {
      numRows_=b.rows();
      numCols_=b.cols();
      a_.resize(numRows_*numCols_);
      for (size_t i=0;i<numRows_;++i)
        for (size_t j=0;j<numCols_;++j)
          a_[i*numCols_+j]=b(i,j);
    }
    
    // column iterator for constant matrices
    class  ConstColIter
    {
      public:
        ConstColIter(const Matrix& matrix, size_t row, size_t col) :
          matrix_(matrix), row_(row), col_(col) 
        {}

        const T &operator*() const { 
          return matrix_(row_, col_); 
        }

        ConstColIter &operator++() {
          ++col_;
          return *this;
        }

        bool operator==(const ConstColIter &other) const {
          return (&matrix_ == &other.matrix_) && (row_ == other.row_) && (col_ == other.col_);
        }

        bool operator!=(const ConstColIter &other) const { 
          return !(*this == other); 
        }

        size_t col() const { 
          return col_;
        }
      protected:
        const Matrix& matrix_;
        const size_t row_;
        size_t col_;
    };

    // column iterator for variable matrices
    class ColIter : public ConstColIter
    {
      public:
        ColIter(Matrix& matrix, size_t row, size_t col) :
          ConstColIter(matrix,row,col), matrix_(matrix) 
        {}
        const T operator*() {
          return matrix_(this->row_,this->col_);
        }
      private:
        Matrix& matrix_;
    };

    // row class for constant matrices
    class ConstRow
    {
      public:
        // STL interface
        using iterator=ConstColIter;
        using const_iterator=ConstColIter;

        ConstColIter begin() const {
          return ConstColIter(matrix_,row_,0);
        }

        ConstColIter end() const {
          return ConstColIter(matrix_,row_,matrix_.cols());
        }

        ConstRow(const Matrix& matrix, size_t row) :
          matrix_(matrix), row_(row)
        {}

        bool operator==(const ConstRow& other) const {
          return (&matrix_ == &other.matrix_) && (row_ == other.row_);
        }

        bool operator!=(const ConstRow& other) const { 
          return !(*this == other); 
        }

        size_t row() const { 
          return row_;
        }
      protected:
        const Matrix& matrix_;
        size_t row_;
    };

    // row class for variable matrices
    class Row
    {
    public:
        // STL interface
        using iterator=ColIter;
        using const_iterator=ConstColIter;
        
        ColIter begin() const {
          return ColIter(matrix_,row_,0);
        }

        ColIter end() const {
          return ColIter(matrix_,row_,matrix_.cols());
        }

        Row(Matrix& matrix, size_t row) :
          matrix_(matrix), row_(row)
        {}

        bool operator==(const Row& other) const {
          return (&matrix_ == &other.matrix_) && (row_ == other.row_);
        }

        bool operator!=(const Row& other) const { 
          return !(*this == other); 
        }

        size_t row() const { 
          return row_;
        }
      protected:
        Matrix& matrix_;
        size_t row_;
    };

    // row iterator for constant matrices
    class  ConstRowIter
    {
      public:
        ConstRowIter(const Matrix& matrix, size_t row) :
          matrix_(matrix), row_(row)
        {}

        ConstRow operator*() const { 
          return ConstRow(matrix_,row_); 
        }

        ConstRowIter &operator++() {
          ++row_;
          return *this;
        }

        bool operator==(const ConstRowIter &other) const {
          return (&matrix_ == &other.matrix_) && (row_ == other.row_);
        }

        bool operator!=(const ConstRowIter &other) const { 
          return !(*this == other); 
        }

        size_t row() const { 
          return row_;
        }
      protected:
        const Matrix& matrix_;
        size_t row_;
    };

    // row iterator for variable matrices
    class RowIter : public ConstRowIter
    {
      public:
        RowIter(Matrix& matrix, size_t row) :
          ConstRowIter(matrix,row), matrix_(matrix)
        {}
        Row operator*() {
          return Row(matrix_,this->row_);
        }
      protected:
        Matrix& matrix_;
    };

    // STL interface
    using iterator = RowIter;
    using const_iterator = ConstRowIter;

    RowIter begin() {
      return RowIter(*this,0);
    }

    ConstRowIter begin() const {
      return ConstRowIter(*this,0);
    }

    RowIter end() {
      return RowIter(*this,numRows_);
    }

    ConstRowIter end() const {
      return ConstRowIter(*this,numRows_);
    }

  protected:
    std::vector<T> a_;    // matrix elements
    size_t numRows_=0;    // number of rows
    size_t numCols_=0;    // number of columns
};

// Set number of matrix rows and columns and 
// initialize matrix elements with a given double value
template<typename T>
void Matrix<T>::resize(size_t numRows, size_t numCols, const T& value) {
  if ((numRows_+numCols_>0) && (numRows_*numCols_==0))
    throw std::out_of_range("Illegal matrix dimensions: " + std::to_string(numRows) + " " + std::to_string(numCols) );
  numRows_=numRows;
  numCols_=numCols;
  a_.resize(numRows_*numCols_,value);
}

// Access matrix element at position (i,j)
template<typename T>
T &Matrix<T>::operator()(size_t i, size_t j) {
#ifndef NDEBUG
  if ((i<0)||(i>=numRows_))
    throw std::out_of_range("Matrix access row index out of range: "+std::to_string(i) + " not in [0:" + std::to_string(numRows_-1) + "]");
  if ((j<0)||(j>=numCols_))
    throw std::out_of_range("Matrix access column index out of range: "+std::to_string(j) + " not in [0:" + std::to_string(numCols_-1) + "]");
#endif
  return a_[i*numCols_+j];
}

// Access matrix element at position (i,j)
template<typename T>
const T& Matrix<T>::operator()(size_t i,size_t j) const {
#ifndef NDEBUG
  if ((i<0)||(i>=numRows_))
    throw std::out_of_range("Matrix access row index out of range: "+std::to_string(i) + " not in [0:" + std::to_string(numRows_-1) + "]");
  if ((j<0)||(j>=numCols_))
    throw std::out_of_range("Matrix access column index out of range: "+std::to_string(j) + " not in [0:" + std::to_string(numCols_-1) + "]");
#endif
  return a_[i*numCols_+j];
}

// Output matrix content
template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& a) {
  os << "(" << a.rows() << "x";
  os << a.cols() << ") matrix:\n";
  for (size_t i=0;i<a.rows();++i) {
    os << std::setprecision(3);
    for (size_t j=0;j<a.cols();++j)
        os << std::setw(5) << a(i,j) << " ";
    os << '\n';
  }
  os << '\n';
  return os;
}

#endif

