#include "trapezregel.h"

Trapezregel::Trapezregel(double a_, double b_, int size_)
{
    a = a_;
    b = b_;
    size = size_;
}

Trapezregel::~Trapezregel()
{
    a = 0;
    b = 0;
    size = 0;
}

double Trapezregel::qTrapez(Funktor &f, double a_, double b_)
{
    return ((b_ - a_) * (f(a_) + f(b_))) / 2;
}

double Trapezregel::operator() (Funktor &f) //override
{
    double h = (b - a) / size;

    double s = a;
    double result = 0;

    for (size_t i = 0; i < size; i++)
    {
        result += Trapezregel::qTrapez(f, s, s + h);
        s = s + h;
    }

    return result;    
}