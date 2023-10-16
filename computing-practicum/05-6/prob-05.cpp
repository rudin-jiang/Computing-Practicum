#include "root.hpp"
#include <cstdio>
#include <cmath>
#include <stdexcept>

#define pi 3.1415926535897931

int main() {
    using std::sin;
    using std::cos;
    using std::tan;

    std::printf("Problem 5\n\n");

    auto fx = [](double x) -> double { return sin(x)/cos(x) - x; };
    auto df = [](double x) -> double { return 1.0/cos(x)/cos(x) - 1.0; };

    const double eps = 1.0e-12;

    double x1 =  4.4;
    double x2 =  7.6;
    double x3 = 10.9;

    double ans1 = newton_root_solver(fx, df, x1, eps);
    double ans2 = newton_root_solver(fx, df, x2, eps);
    double ans3 = newton_root_solver(fx, df, x3, eps);

    std::printf("ans1 = %15.12lf\n", ans1);
    std::printf("ans2 = %15.12lf\n", ans2);
    std::printf("ans3 = %15.12lf\n", ans3);

    return 0;
}