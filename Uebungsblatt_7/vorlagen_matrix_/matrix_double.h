#include <memory>

/**
 * Matrix Class representing matrices of double values
 */

template <class T>
class MatrixClass
{
  public:
   
    // Set number of matrix rows and columns and initialize its elements with value
    void resize(size_t numRows, size_t numCols, const T& value = T() );
    
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
