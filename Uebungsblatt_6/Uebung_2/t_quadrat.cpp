#include <math.h>

#include "t_quadrat.h"

T_Quadrat::T_Quadrat(double a_, double b_)
{
    a = a_;
    b = b_;
}

double T_Quadrat::operator()(double t)
{
    return (2 * pow(t, 2)) + 5;
}

double T_Quadrat::exactIntegral() const
{
    return (((2 * pow(b, 3)) / (3 + 5 * b)) - ((2 * pow(a, 3)) / (3 + 5 * a)));
}