#ifndef NUMVECTOR_H
#define NUMVECTOR_H
#include <math.h>

class NumVector
{
public:
    NumVector(int size);
    ~NumVector();
    double &operator [] (int);
    const double &operator [] (int) const;
    double norm();
    const double norm() const;
    void resize(int);

private:
    int size;
    mutable double cachedNorm;
    double *values;
};

#endif // NUMVECTOR_H
