#ifndef TRAPEZREGEL_H
#define TRAPEZREGEL_H

#include <cmath>

#include "quadraturregel.h"

class Trapezregel : public Quadraturregel
{
private:
    double qTrapez(Funktor &f, double a_, double b_);

public:
    //Variable
    double a, b;
    int size;

    //Funktionen
    Trapezregel(double a_, double b_, int size_);
    ~Trapezregel();
    double operator() (Funktor &f) override;
};

#endif // TRAPEZREGEL_H