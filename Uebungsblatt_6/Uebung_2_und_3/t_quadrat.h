#ifndef T_QUADRAT_H
#define T_QUADRAT_H

#include <math.h>

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

    double operator () (double) override;

    void integrationIntegration(double &, double &) const;
    double exactIntegral() const override; 
};

#endif // T_QUADRAT_H