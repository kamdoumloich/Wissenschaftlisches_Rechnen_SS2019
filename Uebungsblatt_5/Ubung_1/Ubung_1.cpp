#include <iostream>

class Empty
{
};

class EmptyDerived : Empty
{
};

class NonEmpty : Empty
{
public:
    char c;
};

struct Composite
{
    Empty a;
    int b;
};

struct CompositeChar
{
    Empty a;
    char b;
};

struct CompositeLong
{
    Empty a;
    long long b;
};

int main()
{
    Empty e1;
    EmptyDerived e2;
    NonEmpty e3;
    
    std::cout << "Size of Empty : " << sizeof(e1) << std::endl;
    std::cout << "Size of EmptyDerived : " << sizeof(e2) << std::endl;
    std::cout << "Size of NonEmpty : " << sizeof(e3) << std::endl;

    Composite c1;
    std::cout <<"Adresse von c.a : " << &c1.a << std::endl;
    std::cout <<"Adresse von c.b : " << &c1.b << std::endl;

    std::cout << "Size of Object Composite : " << sizeof(c1) << std::endl;
    std::cout << "Size of c.a : " << sizeof(c1.a) << std::endl;
    std::cout << "Size of c.b : " << sizeof(c1.b) << std::endl;

    CompositeChar c2;
    std::cout << "Size of Object CompositeChar : " << sizeof(c2) << std::endl;
    std::cout << "Size of c.a : " << sizeof(c2.a) << std::endl;
    std::cout << "Size of c.b : " << sizeof(c2.b) << std::endl;

    CompositeLong c3;
    std::cout << "Size of Object CompositeLong : " << sizeof(c3) << std::endl;
    std::cout << "Size of c.a : " << sizeof(c3.a) << std::endl;
    std::cout << "Size of c.b : " << sizeof(c3.b) << std::endl;

    return 0;
}
