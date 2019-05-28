#ifndef T_SINUS_H
#define T_SINUS_H

#include <math.h>

#include "testfunktion.h"
#include "funktor.h"

class T_Sinus : public TestFunktion
{
private:
    double a, b;

public:
    //Variable

    //Funktionen
    T_Sinus() = default;
    T_Sinus(double, double);

    double operator()(double) override;

    void integrationIntegration(double &, double &) const;
    double exactIntegral() const override;
};

#endif // T_SINUS_H