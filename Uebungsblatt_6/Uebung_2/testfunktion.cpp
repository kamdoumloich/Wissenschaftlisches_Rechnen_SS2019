#include <iostream>

#include "testfunktion.h"

void TestFunktion::integrationIntervall(double &l_, double &r_) const
{
    std::cout << "[l, r] = " << l_ << " " << r_ << std::endl;
}

double TestFunktion::exactIntegral() const
{
    return 0;
}