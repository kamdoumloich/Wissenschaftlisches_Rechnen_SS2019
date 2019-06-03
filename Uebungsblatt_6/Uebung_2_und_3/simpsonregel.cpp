#include "simpsonregel.h"

Simpsonregel::Simpsonregel(double a_, double b_, int size_)
{
    a = a_;
    b = b_;
    size = size_;
}

Simpsonregel::~Simpsonregel()
{
    a = 0;
    b = 0;
    size = 0;
}

double Simpsonregel::qSimpson(Funktor &f, double a_, double b_)
{
    return (b_ - a_) * (f(a_) + (4 * f((a_ + b_) / 2) + f(b_))) / 6;
}

double Simpsonregel::operator()(Funktor &f) //override
{
    double h = (b - a) / size;

    double s = a;
    double result = 0;

    for (size_t i = 0; i < size; i++)
    {
        result += Simpsonregel::qSimpson(f, s, s + h);
        s = s + h;
    }

    return result;    
}