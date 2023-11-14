#include "integrate.hpp"
#include <cmath>

#define pi  3.1415926535897931
#define ln2 0.6931471805599453

int main() {
    using std::sin;
    using std::abs;

    std::printf("Problem 6\n\n");

    auto fun = [](double x) -> double { if (abs(x) < 1e-8) return 1.0; else return sin(x) / x; };

    for (int k = 1; k <= 6; ++k) {
        double x = k * pi / 3.0;
        double intVal = composite_simp_integrate(fun, 0.0, x, 8);
        std::printf("k = %d    x = %5.3lf    f(x) = %12.10lf\n", k, x, intVal);
    }

    return 0;
}