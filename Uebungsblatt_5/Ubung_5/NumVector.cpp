#include <iostream>
#include "NumVector.h"

NumVector::NumVector(int size)
{
    this->size = size;
    this->cachedNorm = -1;
    this->values = new double[size];
}

NumVector::~NumVector()
{
    this->size = 0;
    this->cachedNorm = 0;
    delete [] values;
}

double &NumVector::operator[](int index)
{
    if(index < 0 || index >= this->size)
        std::cout << "Error: Index: " << index << " is out of Array " << std::endl;

    return this->values[index];
}

const double &NumVector::operator[](int index) const
{
    if(index < 0 || index >= this->size)
        std::cout << "Error: Index: " << index << " is out of Array " << std::endl;

    return this->values[index];
}

NumVector operator * (const NumVector &v1, const NumVector &v2)
{
    NumVector tmp(v1.size);
    if(v1.size != v2.size)
        std::cout << "Error: Incompatibel Length " << std::endl;
    else
      for(int i = 0; i < v1.size; ++i)
        tmp[i] = v1.values[i]*v2.values[i];

    return tmp;
}

double NumVector::norm()
{
    if(this->cachedNorm != -1)
        return this->cachedNorm;

    double result = 0;
    for(int i = 0; i < this->size; ++i)
        result += this->values[i] * this->values[i];

    this->cachedNorm = sqrt(result);
    return this->cachedNorm;
}

const double NumVector::norm() const
{
    if(this->cachedNorm != -1)
        return this->cachedNorm;

    double result = 0;
    for(int i = 0; i < this->size; ++i)
        result += this->values[i] * this->values[i];

    this->cachedNorm = sqrt(result);
    return this->cachedNorm;
}

void NumVector::resize(int size)
{
    double *tmp = new double[size];
    for(int i = 0; i < size; ++i)
      tmp[i] = values[i];
    delete [] values;
    values = new double[size];
    for(int i = 0; i < size; ++i)
      values[i] = tmp [i];
    delete [] tmp;
}
