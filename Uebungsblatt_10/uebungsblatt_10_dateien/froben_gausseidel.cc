#include "nummatrix.h"
#include <cmath>
#include <complex>
#include <algorithm>

template<class M>
typename M::value_type frobeniusnorm(const M& matrix)
{
  typename M::value_type result = typename M::value_type();
  for (auto row: matrix)
    for (auto x: row)
      result+=x*x;
  return std::sqrt(result);
}

template<class M, typename T>
void gaussseidel(const M& A, const std::vector<T>& b, std::vector<T>& x, int maxIter)
{
  for (int m=0; m<maxIter; ++m)
    for (auto row = A.begin(); row != A.end(); ++row)
    {
      typename M::value_type result = typename M::value_type();
      typename M::range_type i = row.row();
      typename M::value_type diag;
      for (auto col = (*row).begin(); col != (*row).end(); ++col) {
        if (i == col.col())
          diag = *col;
        else
          result += *col * x[col.col()];
      }
      x[i]=(b[i]-result)/diag;
    }
}

int main() {   
  // Define a matrix A
  NumMatrix<std::complex<float>> A(4,4);
  std::cout << "A : \n" << A;
  std::cout << "Frobenius Norm: " << frobeniusnorm(A) << '\n';
  
  NumMatrix<double> B(10,10,1.);
  std::cout << "B : \n" << B;
  std::cout << "Frobenius Norm: " << frobeniusnorm(B) << '\n';
  
  B*=-2.;
  std::cout << "-2. * B : \n" << B;
  std::cout << "Frobenius Norm: " << frobeniusnorm(B) << '\n';
  A.resize(3,3);
  A(0,0)=2.;
  A(0,1)=1.;
  A(0,2)=0.;
  A(1,0)=1.;
  A(1,1)=3.;
  A(1,2)=2.;
  A(2,0)=0.;
  A(2,1)=1.;
  A(2,2)=-4.;
  std::cout << A;
  std::vector<std::complex<float>> b = {1., 2., 3.};
  std::vector<std::complex<float>> x(3);
  gaussseidel(A,b,x,100);
  std::for_each(A.begin(), A.end(), [](const auto& r){std::for_each(r.begin(), r.end(),[](const auto& x){std::cout << x << ' ';});std::cout << '\n';});
  std::cout << '\n';
  std::for_each(x.begin(), x.end(), [](const auto& x){std::cout << x << '\n';});
}
