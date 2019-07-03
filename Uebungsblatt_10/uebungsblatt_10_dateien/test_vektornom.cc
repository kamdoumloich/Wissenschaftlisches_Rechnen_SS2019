#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

template<typename T>
void norm_sqrt(const T& elt)
{
  std::cout << "||A||2 = " << std::sqrt(std::pow(elt, 2));
}

template<typename T>
void norm_summe(const T& elt)
{
  T tmp;

  std::cout << "||A||2 = " << std::sqrt(std::pow(elt, 2));
}

int main() {   
  // Define a matrix A
  std::vector<int> A(2);

  for (size_t i=0;i<A.size();++i)
    A[i] = 2;

  std::for_each(A.begin(), A.end(), norm_sqrt<int>);
}
