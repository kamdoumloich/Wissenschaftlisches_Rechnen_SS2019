#include "t_sinus.h"
#include <math.h>

T_Sinus::T_Sinus(double a_, double b_)
{
    a = a_;
    b = b_;
}

double T_Sinus::operator()(double t_)
{
    return ((t_ * std::sin(t_)) / M_PI);
}

double T_Sinus::exactIntegral() const
{
    return ((std::sin(b) - b * std::cos(b)) - (std::sin(b) - b * std::cos(b))) / M_PI;
}