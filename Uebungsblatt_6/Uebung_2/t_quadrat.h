#ifndef T_QUADRAT_H
#define T_QUADRAT_H

#include <cmath>

#include "testfunktion.h"
#include "funktor.h"

class T_Quadrat: public TestFunktion
{
private:
    double a, b;

public:
    //Variable

    //Funktionen
    T_Quadrat() = default;
    T_Quadrat(double, double);

    double operator () (double t) override;

    void integrationIntegration(double &, double &) const;
    virtual double exactIntegral() const = 0; 
};

#endif // T_QUADRAT_H