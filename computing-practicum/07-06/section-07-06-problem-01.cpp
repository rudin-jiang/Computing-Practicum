#include "integrate.hpp"
#include "gauss-legendre.hpp"
#include <cstdio>

int main() {
    double a = 0.0, b = 1.0;
    auto func = [](double x) -> double { return 4.0 / (1.0 + x*x); };
    
    std::printf("Problem 1\n\n");
    
    std::printf("Problem 1.1\n");
    
    double h = (b - a) / 4.0;
    double x0 = a + 0.0 * h;
    double x1 = a + 1.0 * h;
    double x2 = a + 2.0 * h;
    double x3 = a + 3.0 * h;
    double x4 = a + 4.0 * h;

    double trapInt = trap_integrate(func(x0), func(x4), a, b);
    double simpInt = simp_integrate(func(x0), func(x2), func(x4), a, b);
    double coteInt = cote_integrate(func(x0), func(x1), func(x2), func(x3), func(x4), a, b);

    std::printf("trap int: %15.10lf\n", trapInt);
    std::printf("simp int: %15.10lf\n", simpInt);
    std::printf("cote int: %15.10lf\n", coteInt);
    std::printf("\n");

    std::printf("Problem 1.2\n");
    
    std::printf("m = 4\n");
    double comTrapIntM4 = composite_trap_integrate(func, a, b, 4);
    double comSimpIntM4 = composite_simp_integrate(func, a, b, 4);

    std::printf("composite trap int: %15.10lf\n", comTrapIntM4);
    std::printf("composite simp int: %15.10lf\n", comSimpIntM4);

    std::printf("m = 8\n");
    double comTrapIntM8 = composite_trap_integrate(func, a, b, 8);
    double comSimpIntM8 = composite_simp_integrate(func, a, b, 8);

    std::printf("composite trap int: %15.10lf\n", comTrapIntM8);
    std::printf("composite simp int: %15.10lf\n", comSimpIntM8);
    std::printf("\n");

    std::printf("Problem 1.3\n");

    double rombInt = romberg_integrate(func, a, b, 1.0e-8);
    std::printf("romberg int: %15.10lf\n", rombInt);
    std::printf("\n");

    std::printf("Problem 1.4\n");

    double glIntN1 = gauss_legendre_integrate_a_b_(func, a, b, 1);
    double glIntN2 = gauss_legendre_integrate_a_b_(func, a, b, 2);
    double glIntN4 = gauss_legendre_integrate_a_b_(func, a, b, 4);

    std::printf("Gauss-Legendre n = 1 :  %15.10lf\n", glIntN1);
    std::printf("Gauss-Legendre n = 2 :  %15.10lf\n", glIntN2);
    std::printf("Gauss-Legendre n = 4 :  %15.10lf\n", glIntN4);



    return 0;
}