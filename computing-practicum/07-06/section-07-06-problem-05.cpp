#include "integrate.hpp"
#include "gauss-legendre.hpp"
#include <cmath>

#define pi  3.1415926535897931
#define ln2 0.6931471805599453

int main() {
    using std::exp;

    std::printf("Problem 5\n\n");

    auto func = [](double x) -> double { return exp(-x*x); };
    double intValN1 = gauss_legendre_integrate_a_b_(func, 0.0, 1.0, 4);
    double intValN3 = gauss_legendre_integrate_a_b_(func, 0.0, 3.0, 4);
    double intValN10 = gauss_legendre_integrate_a_b_(func, 0.0, 10.0, 4);
    double accIntVal = std::sqrt(pi) / 2.0;

    std::printf("N =  1: %15.10lf\n", intValN1);
    std::printf("N =  3: %15.10lf\n", intValN3);
    std::printf("N = 10: %15.10lf\n", intValN10);
    std::printf("\n");

    std::printf("Accuracy value: %15.10lf\n", accIntVal);

    return 0;
}