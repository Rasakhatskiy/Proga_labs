#include <cmath>
#include "Formula_09.h"

double Formula_09::Start(double x, double eps)
{
    double d = x;
    double sum = x;
    double a = x;
    double b = 1;
    double square = x * x;
    int sign = -1;
    do
    {
        a *= square;
        b += 2;
        d = a / b;
        sum += sign * d;
        sign *= -1;
    }
    while (std::abs(d) < eps);
    return sum;
}
