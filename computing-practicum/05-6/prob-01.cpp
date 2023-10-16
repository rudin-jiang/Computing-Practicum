#include "root.hpp"
#include <cstdio>
#include <cmath>

#define pi  3.1415926535897931
#define ln2 0.6931471805599453

int main() {
    
    using std::exp;
    using std::cos;

    std::printf("Problem 1\n\n");

    auto f1 = [](double x) -> double { return x*x*x + 3.0*x - 5.0; };
    auto f2 = [](double x) -> double { return x - exp(-x); };
    auto f3 = [](double x) -> double { return x*x - cos(x); };
    auto f4 = [](double x) -> double { return 7.0*x*x - 3.0*x + 4.0/x - 30.0; };

    double a1 =     1.0,    b1 =     2.0;
    double a2 =     0.5,    b2 =     ln2;
    double a3 = 0.25*pi,    b3 = 0.75*pi;
    double a4 =     2.0,    b4 =     2.5;

    const double eps = 1.0e-6;

    double ans1 = bisect_root_slover(f1, a1, b1, eps);
    double ans2 = bisect_root_slover(f2, a2, b2, eps);
    double ans3 = bisect_root_slover(f3, a3, b3, eps);
    double ans4 = bisect_root_slover(f4, a4, b4, eps);

    std::printf("ans1 = %8.6lf\n", ans1);
    std::printf("ans2 = %8.6lf\n", ans2);
    std::printf("ans3 = %8.6lf\n", ans3);
    std::printf("ans4 = %8.6lf\n", ans4);

    return 0;
}