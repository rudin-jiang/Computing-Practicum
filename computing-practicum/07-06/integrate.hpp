#pragma once

#include <cstddef>
#include <vector>

inline double trap_integrate(double fa, double fb, double a, double b) {
    return (fa + fb) * (b - a) / 2.0;
}

inline double simp_integrate(double fa, double fm, double fb, double a, double b) {
    return (fa + 4.0*fm + fb) * (b - a) / 6.0;
}

inline double cote_integrate(double f0, double f1, double f2, double f3, double f4, double a, double b) {
    return (7.0*(f0 + f4) + 32.0*(f1 + f3) + 12.0*f2) * (b - a) / 90.0;
}


// T_{m}^{(1)}
template<class Fn>
double composite_trap_integrate(const Fn &func, double a, double b, std::size_t m) {
    std::vector<double> funcVals(m + 1, 0.0);
    double h = (b - a) / double(m);

    for (std::size_t i = 0; i <= m; ++i) {
        double xi = a + i * h;
        funcVals[i] = func(xi);
    }

    double intVal = 0.0;
    for (std::size_t i = 1; i < m; ++i) {
        intVal += funcVals[i];
    }

    intVal *= 2;
    intVal += (funcVals[0] + funcVals[m]);

    return intVal * h / 2.0;
}


// T_{m}^{(2)}
template<class Fn>
double composite_simp_integrate(const Fn &func, double a, double b, std::size_t m) {
    double Tm1 = composite_trap_integrate(func, a, b, m);
    double T2m1 = composite_trap_integrate(func, a, b, 2*m);

    return (4.0 * T2m1 - Tm1) / 3.0;
}


// T_{m}^{(3)}
template<class Fn>
double composite_cote_integrate(const Fn &func, double a, double b, std::size_t m) {
    double Tm2 = composite_simp_integrate(func, a, b, m);
    double T2m2 = composite_simp_integrate(func, a, b, 2*m);

    return (16.0 * T2m2 - Tm2) / 15.0;
}

template<class Fn>
double romberg_integrate(const Fn &func, double a, double b, double eps = 1.0e-8) {
    // 
    return 0.0;
}




