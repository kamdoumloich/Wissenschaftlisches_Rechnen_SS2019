#ifndef TRAPEZREGEL_H
#define TRAPEZREGEL_H

#include <math.h>

#include "quadraturregel.h"

class Trapezregel : public Quadraturregel
{
private:
    double qTrapez(Funktor &, double, double);

public:
    //Variable
    double a, b;
    int size;

    //Funktionen
    Trapezregel(double, double, int);
    ~Trapezregel();
    double operator() (Funktor &) override;
};

#endif // TRAPEZREGEL_H