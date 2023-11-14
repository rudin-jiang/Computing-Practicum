#include "integrate.hpp"
#include <vector>
#include <cmath>

#define pi  3.1415926535897931
#define ln2 0.6931471805599453

int main() {
    using std::exp;
    using std::abs;
    using std::sin;
    using std::cos;
    using std::sqrt;

    std::printf("Problem 3\n\n");

    auto func1 = [](double x) -> double { return exp(x*x); };
    auto func2 = [](double x) -> double { if (abs(x) < 1e-8) return 0.0; return (1 - cos(x)) / x; };
    auto func3 = [](double x) -> double { return sqrt(1.0 - x*x*x); };
    auto func4 = [](double x) -> double { return exp(-x) / (1.0 + x*x); };

    double a1 = 0.0, b1 = 1.0;
    double a2 = 0.0, b2 =  pi;
    double a3 = 0.0, b3 = 1.0;
    double a4 = 0.0, b4 = 2.0;

    

    double compTrapInt1 = composite_trap_integrate(func1, a1, b1, 16);
    double compTrapInt2 = composite_trap_integrate(func2, a2, b2,  8);
    double compTrapInt3 = composite_trap_integrate(func3, a3, b3,  8);
    double compTrapInt4 = composite_trap_integrate(func4, a4, b4,  8);
    double compSimpInt1 = composite_simp_integrate(func1, a1, b1, 16);
    double compSimpInt2 = composite_simp_integrate(func2, a2, b2,  8);
    double compSimpInt3 = composite_simp_integrate(func3, a3, b3,  8);
    double compSimpInt4 = composite_simp_integrate(func4, a4, b4,  8);

    std::printf("Problem 3.1\n");
    std::printf("composite trap int: %15.10lf\n", compTrapInt1);
    std::printf("composite simp int: %15.10lf\n", compSimpInt1);
    std::printf("\n");

    std::printf("Problem 3.2\n");
    std::printf("composite trap int: %15.10lf\n", compTrapInt2);
    std::printf("composite simp int: %15.10lf\n", compSimpInt2);
    std::printf("\n");

    std::printf("Problem 3.3\n");
    std::printf("composite trap int: %15.10lf\n", compTrapInt3);
    std::printf("composite simp int: %15.10lf\n", compSimpInt3);
    std::printf("\n");

    std::printf("Problem 3.4\n");
    std::printf("composite trap int: %15.10lf\n", compTrapInt4);
    std::printf("composite simp int: %15.10lf\n", compSimpInt4);
    std::printf("\n");

    return 0;
}