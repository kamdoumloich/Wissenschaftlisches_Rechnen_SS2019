#ifndef QUADRATURREGEL_H
#define QUADRATURREGEL_H

#include "funktor.h"

class Quadraturregel
{
public:
    virtual double operator () (Funktor &f) = 0;
};

#endif // QUADRATURREGEL_H