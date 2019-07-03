#include "num_matrix.h"
#include "matrix_double.h"
#include <iostream>
#include <cstdlib>

int main()
{   
    // Define a matrix A
    NumMatrixClass<double> A(4,4);
    std::cout << "A : " <<std::endl;
    A.print();

    // Define a square tridiagonal matrix A
    for (size_t i=0;i<A.rows();++i)  
      A(i,i) = 2.0;
    for (size_t i=0;i<A.rows()-1;++i) 
      A(i+1,i) = A(i,i+1) = -1.0;

    // Define a matrix C of same content as A
    NumMatrixClass<double> C(A);
    std::cout << "C : " <<std::endl;
    C.print();
    
    A = 2.*C;
    std::cout << "A = 2 * C" <<std::endl;
    A.print();
    
    A = C*2.;
    std::cout << "A = C * 2." <<std::endl;
    A.print();
    
    A = C+A;
    std::cout << "A = C + A" <<std::endl;
    A.print();
    
    // Resize A
    A.resize(5,5);
    for (size_t i=0;i<A.rows();++i)  
      A(i,i) = 2.0;
    for (size_t i=0;i<A.rows()-1;++i) 
      A(i+1,i) = A(i,i+1) = -1.0;

    // Print A
    std::cout << "A :" <<std::endl;
    A.print();
 
}

