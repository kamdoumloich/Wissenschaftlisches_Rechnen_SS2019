#ifndef SIMPSONREGEL_H
#define SIMPSONREGEL_H

#include <math.h>

#include "quadraturregel.h"

class Simpsonregel: public Quadraturregel
{
private:
    double qSimpson(Funktor &, double, double);

public:
    //Variable
    double a, b;
    int size;

    //Funktionen
    Simpsonregel(double, double, int);
    ~Simpsonregel();
    double operator() (Funktor &) override;
};

#endif // SIMPSONREGEL_H