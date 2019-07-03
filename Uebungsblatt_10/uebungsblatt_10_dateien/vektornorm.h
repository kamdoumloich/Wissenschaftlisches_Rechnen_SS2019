#include <algorithm>
#include <iostream>
#include <vector>

#ifndef _VEKTORNORM_H_
#define _VEKTORNORM_H_

template<class T> 
class Vektor
{
    public:
    explicit Vektor(size_t n);
    T& operator[](size_t);
};

#endif