#include "integrate.hpp"
#include <cstdio>

int main() {

    std::printf("Problem 4\n\n");

    auto func = [](double x) -> double { return 1.0 / x; };
    double a = 1.0, b = 2.0;
    double eps = 1.0e-8;

    double intVal = romberg_integrate(func, a, b, eps);
    std::printf("int value = %15.10lf\n", intVal);

    return 0;
}