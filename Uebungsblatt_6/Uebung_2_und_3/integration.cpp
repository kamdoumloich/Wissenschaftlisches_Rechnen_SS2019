#include <iostream>

#include "integration.h"
#include "trapezregel.h"
#include "simpsonregel.h"

double Integration::konvergenceOrdnung(TestFunktion &f, Quadraturregel &q1, Quadraturregel &q2)
{
    double EOC = 0, EN = 0, E2N = 0;

    EN = f.exactIntegral() - q1(f);
    E2N = f.exactIntegral() - q2(f);

    if (EN != 0 && E2N != 0)
    {
        EOC = std::log(EN/E2N)/std::log(2);
    }

    return EOC;    
}

void Integration::printTestQuadrature(double a_, double b_, double size_, TestFunktion &f, Quadraturregel &q1, Quadraturregel &q2)
{
    std::cout << "[a,b] = [" << a_ << "," << b_ << "]" << " size = " << size_ << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Numerische Integral " << q1(f) << std::endl;
    std::cout << "Exactes Integral " << f.exactIntegral() << std::endl;
    std::cout << "Konvergence Zuordnung " << Integration::konvergenceOrdnung(f, q1, q2) << std::endl;
    ;
    std::cout << std::endl;
}

void Integration::testTrapezregel(double a_, double b_, double size_, TestFunktion &f)
{
    Trapezregel q(a_, b_, size_);
    Trapezregel q2n(a_, b_, 2 * size_);
    printTestQuadrature(a_, b_, size_, f, q, q2n);
}

void Integration::testSimpsonregel(double a_, double b_, double size_, TestFunktion &f)
{
    Simpsonregel q(a_, b_, size_);
    Simpsonregel q2n(a_, b_, 2 * size_);
    printTestQuadrature(a_, b_, size_, f, q, q2n);
}
