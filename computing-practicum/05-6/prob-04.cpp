#include "root.hpp"
#include <cstdio>
#include <cmath>
#include <stdexcept>

#define pi 3.1415926535897931

int main() {
    using std::sin;
    using std::cos;

    std::printf("Problem 4\n\n");

    const double e = 0.2;
    const double eps = 1.0e-10;
    double a = 0.0, b = pi;

    for (int k = 1; k <=8; ++k) {
        double x = double(k) / 8.0;

        auto fx = [e, x](double y) -> double { return y - x - e*sin(y); };
        auto df = [e, x](double y) -> double { return 1.0 - e*cos(y); };

        double ansk = newton_root_solver(fx, df, a, b, eps);
        std::printf("k = %d:  y = %13.10lf\n", k, ansk);
    }

    return 0;
}