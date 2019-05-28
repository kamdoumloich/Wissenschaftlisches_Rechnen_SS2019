#include <iostream>

#include "funktor.h"
#include "integration.h"
#include "quadraturregel.h"
#include "simpsonregel.h"
#include "t_quadrat.h"
#include "t_sinus.h"
#include "testfunktion.h"
#include "trapezregel.h"
#include "testfunktion.h"

int main();

int main()
{
    int size = 100;
    double a = 0.;
    double b = 0.;

    a = -3.;
    b = 13.;

    T_Quadrat t_quadrat(a, b);
    Integration *integrall;

    std::cout << "Trapezregel 2*t*t+5" << std::endl;
    integrall->testTrapezregel(a, b, size, t_quadrat);
    std::cout << "simpson 2*t*t+5" << std::endl;
    integrall->testSimpsonregel(a, b, size, t_quadrat);

    a = 0.;
    b = 2 * M_PI;

    T_Sinus t_sinus(a, b);
    std::cout << "Trapezregel t*sin(t)/M_PI" << std::endl;
    integrall->testTrapezregel(a, b, size, t_sinus);
    std::cout << "Simpson t*sin(t)/M_PI" << std::endl;
    integrall->testSimpsonregel(a, b, size, t_sinus);

    return 0;
}