#ifndef TESTFUNKTIONCLASS_H
#define TESTFUNKTIONCLASS_H

#include <math.h>

#include "quadraturregel.h"
#include "funktor.h"

class TestFunktion: public Funktor
{
public:
    //Variable

    //Funktionen
    TestFunktion() = default;
    ~TestFunktion() = default;

    void integrationIntervall(double &, double &) const;
    virtual double exactIntegral() const = 0; 
};

#endif // TESTFUNKTIONCLASS_H