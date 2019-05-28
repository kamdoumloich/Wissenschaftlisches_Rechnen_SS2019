#ifndef INTEGRATION_H
#define INTEGRATION_H

//#include "pi.h" schon in math.h
#include <math.h>

#include "quadraturregel.h"
#include "funktor.h"
#include "testfunktion.h"

class Integration
{
public:
    double konvergenceOrdnung(TestFunktion, Quadraturregel, Quadraturregel);
};

#endif // INTEGRATION_H