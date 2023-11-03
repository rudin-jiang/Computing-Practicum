#include "root.hpp"
#include <cstdio>
#include <cmath>
#include <stdexcept>

// calculate A^(1/n) using newton's method
double pow_1_n(double A, int n) {
    using std::pow;

    if (A <= 0) throw std::invalid_argument("");
    if (n == 0) throw std::invalid_argument("");

    if (n ==  1) return A;
    if (n == -1) return 1.0 / A;

    bool negPow = (n < 0);
    if (negPow) n = -n;

    auto fx = [=](double x) -> double { return pow(x, n) - A; };
    auto df = [=](double x) -> double { return n*pow(x, n-1); };

    double la = 1.0e-10;
    double rb = A;

    const double eps = 1.0e-10;

    double ans = newton_root_solver(fx, df, la, rb, eps);

    return negPow ? 1.0 / ans : ans;
}



int main() {

    std::printf("Problem 2\n\n");

    double ans1 = pow_1_n(2.0,  3);
    double ans2 = pow_1_n(9.0, -5);

    std::printf("ans1 = %15.10lf\n", ans1);
    std::printf("ans2 = %15.10lf\n", ans2);
    
    return 0;
}