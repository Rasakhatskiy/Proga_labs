#include "Formula_07.h"
#include <cmath>

double Formula_07::Start(double x, double eps) {
    double d = 1;
    double sum = 1;
    do
    {
        d *= -1 * x;
        sum += d;
    }
    while (std::abs(d) < eps);
    return sum;
}
