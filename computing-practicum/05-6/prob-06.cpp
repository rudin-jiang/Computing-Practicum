#include "root.hpp"
#include <cstdio>
#include <cmath>
#include <stdexcept>

#define pi 3.1415926535897931

int main() {
    using std::sin;
    using std::cos;
    using std::tan;

    std::printf("Problem 6\n\n");

    auto fx = [](double x) -> double { return 1.0/tan(x) - 1.0/x + x/2.0; };
    auto df = [](double x) -> double { return 0.5 + 1.0/x/x - 1.0/sin(x)/sin(x); };

    const double eps = 1.0e-12;
    double x1 = 2.0;
    double x2 = 6.0;

    double ans1 = newton_root_solver(fx, df, x1, eps);
    double ans2 = newton_root_solver(fx, df, x2, eps);

    std::printf("ans1 = %15.12lf\n", ans1);
    std::printf("ans2 = %15.12lf\n", ans2);

    return 0;
}