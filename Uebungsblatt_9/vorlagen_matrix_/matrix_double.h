#include <memory>
#include <math.h>
#include <iostream>
#include <stdexcept>
#include <iomanip>

/**
 * Matrix Class representing matrices of double values
 */

template <class T>
class MatrixClass
{
  public:
   
    // Set number of matrix rows and columns and initialize its elements with value
    void resize(size_t numRows, size_t numCols, const T& value = T() )
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
    T& operator()(size_t i, size_t j);
    T operator()(size_t i, size_t j) const;
    
    // Arithmetic functions 
    MatrixClass<T> &operator*=(T x);
    MatrixClass<T> &operator+=(const MatrixClass<T> &b);

    // Output matrix content
    void print() const;
    
    // Returns number of matrix raws
    size_t rows() const {
      return numRows_;
    }
    
    // Returns number of matrix columns
    size_t cols() const {
      return numCols_;
    }
    
    MatrixClass<T>& operator=(const MatrixClass<T>& b)
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
    MatrixClass(size_t numRows, size_t numCols, const T& value=T()) :
                numRows_(numRows), numCols_(numCols) {      
      if ((numRows_+numCols_>0) && (numRows_*numCols_==0)) {
        numRows_=0;
        numCols_=0;
      }
      a_=std::unique_ptr<T[]>(new T[numRows_*numCols_]);
      for (size_t j=0;j<numRows_*numCols_;++j)
        a_[j]=value;
    }
    
    MatrixClass(size_t numElem) : MatrixClass(numElem,numElem)
    {}
    
    MatrixClass() = default;

    MatrixClass(const MatrixClass<T> &b)
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
MatrixClass<T> operator*(const MatrixClass<T> &a, T x);
template <class T>
MatrixClass<T> operator*(T x, const MatrixClass<T> &a);
template <class T>
MatrixClass<T> operator+(const MatrixClass<T> &a, const MatrixClass<T> &b);

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

//frobeniusnorm funktion
template <class M>
double frobeniusnorm(const M& matrix)
{
  double tmp = 0.;
  for (size_t i = 0; i < matrix.cols(); i++)
  {
    for (size_t j = 0; j < matrix.rows(); j++)
    {
      tmp += pow(matrix(i,j), 2);
    }
  }
  return sqrt(tmp);
}

// Neue Funktion
// template<class M, typename T>
// void gaussseidel (const M& A, const std::vector<T>& b, std::vector<T>& x, int maxIter)
// {

// }