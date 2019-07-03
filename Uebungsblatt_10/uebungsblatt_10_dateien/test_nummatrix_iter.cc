#include "nummatrix.h"

int main() {   
  // Define a matrix A
  NumMatrix<float> A(4,4);
  std::cout << "A : \n" << A;
  
  // Define a square tridiagonal matrix A
  for (size_t i=0;i<A.rows();++i)  
    A(i,i) = 2.0;
  for (size_t i=0;i<A.rows()-1;++i) 
    A(i+1,i) = A(i,i+1) = -1.0;

  // Define a matrix C of same content as A
  NumMatrix<double> C(A);
  std::cout << "C : \n" << C;
  
  A = 2.*C;
  std::cout << "A = 2. * C: \n" << A;
  
  A = C*2.;
  std::cout << "A = C * 2.: \n" << A;
  
  A = C+A;
  std::cout << "A = C + A: \n" << A;
  
  // Resize A
  A.resize(5,5);
  std::cout << "A : \n" << A;
  for (size_t i=0;i<A.rows();++i)  
    for (size_t j=0;j<A.cols();++j) {
      if (i==j)
        A(i,i) = 2.0;
      else if ((j==(i-1)) || (j==i+1))
        A(i,j) = -1.0;
      else
        A(i,j) = 0.;      
    }
  std::cout << "A : \n" << A;
  try {
    NumMatrix<double> D(4,0);
  }
  catch(std::out_of_range& excp) {
    std::cout << excp.what() << '\n';
  }
  try {
    NumMatrix<double> D(4,5);
    A += D;
  }
  catch(std::out_of_range& excp) {
    std::cout << excp.what() << '\n';
  }
  try {
    C(4,3) = 3;
  }
  catch(std::out_of_range& excp) {
    std::cout << excp.what() << '\n';
  }
  try {
    C(3,4) = 3;
  }
  catch(std::out_of_range& excp) {
    std::cout << excp.what() << '\n';
  }
  for (auto r = A.begin(); r != A.end();++r) {
    std::cout << r.row() << ": ";
    auto k=r;
    if (k==r)
      std::cout << " row matches\n";
    for (auto x = (*r).begin(); x != (*r).end();++x) {
      auto l=x;
      std::cout << x.col() << " ";
      if (l==x)
        std::cout << " col matches ";
    }
    std::cout << '\n';
  }
  std::cout << '\n';
  for (auto  r : A) {
    std::cout << std::setprecision(3);
    std::cout << r.row() << ": ";
    for (auto x : r)
      std::cout << std::setw(5) << x << ' ';
    std::cout << '\n';
  }
  std::cout << '\n';
  const auto E = A;
  for (auto r = E.begin(); r != E.end();++r) {
    std::cout << r.row() << ": ";
    auto k=r;
    if (k==r)
      std::cout << " row matches\n";
    for (auto x = (*r).begin(); x != (*r).end();++x) {
      auto l=x;
      std::cout << x.col() << " ";
      if (l==x)
        std::cout << " col matches ";
    }
    std::cout << '\n';
  }
  std::cout << '\n';
  for (auto  r : E) {
    std::cout << std::setprecision(3);
    std::cout << r.row() << ": ";
    for (auto x : r)
      std::cout << std::setw(5) << x << ' ';
    std::cout << '\n';
  }

}
