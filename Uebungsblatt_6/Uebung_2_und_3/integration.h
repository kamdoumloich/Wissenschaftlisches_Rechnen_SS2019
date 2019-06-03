#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <math.h>

#include "quadraturregel.h"
#include "funktor.h"
#include "testfunktion.h"

class Integration
{
private:

public:
    double konvergenceOrdnung(TestFunktion &, Quadraturregel &, Quadraturregel &);
    void printTestQuadrature(double, double, double, TestFunktion &, Quadraturregel &, Quadraturregel &);
    void testTrapezregel(double, double, double, TestFunktion &);
    void testSimpsonregel(double, double, double, TestFunktion &);
};

#endif // INTEGRATION_H