#include "matrix_double.cc"
#include <iostream>

int main()
{   
    // Define a matrix A
    MatrixClass<double> A(4, 4);
    std::cout << "A : \n";
    A.print();

    // Define a square tridiagonal matrix A
    for (size_t i=0;i<A.rows();++i)  
      A(i,i) = 2.0;
    for (size_t i=0;i<A.rows()-1;++i) 
      A(i+1,i) = A(i,i+1) = -1.0;

    // Define a matrix C of same content as A
    MatrixClass<double> C(A);
    std::cout << "C : \n";
    C.print();
    
    A = 2.*C;
    std::cout << "A = 2 * C\n";
    A.print();

    A = C*2.;
    std::cout << "A = C * 2.\n";
    A.print();
    
    A = C+A;
    std::cout << "A = C + A\n";
    A.print();
    
    // Resize A
    A.resize(5,5);
    for (size_t i=0;i<A.rows();++i)  
      A(i,i) = 2.0;
    for (size_t i=0;i<A.rows()-1;++i) 
      A(i+1,i) = A(i,i+1) = -1.0;

    // Print A
    std::cout << "A :\n";
    A.print();

    //Test von Exception
    try
    {
      A(6, 6) = 1.;
    }
    catch (const std ::exception &e)
    {
      std ::cerr << " Exception " << e.what() << std ::endl;
      return 1;
    }

}
