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
    return this->values[index];
}

const double &NumVector::operator[](int index) const
{
    return this->values[index];
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
