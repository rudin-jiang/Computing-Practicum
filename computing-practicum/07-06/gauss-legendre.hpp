#include <vector>
#include <cassert>
#include <stdexcept>

template<class Fn>
double gauss_legendre_integrate_norm(const Fn &func, std::size_t n) {
    if (n < 0 || n > 4) throw std::runtime_error("error parameter.");

    if (n == 1) {
        return   1.0000000000 * func(-0.5773502692)
               + 1.0000000000 * func(+0.5773502692);
    }

    if (n == 2) {
        return   0.5555555556 * func(-0.7745966692)
               + 0.5555555556 * func(+0.7745966692)
               + 0.8888888889 * func(+0.0000000000);
    }

    if (n == 3) {
        return   0.6521451549 * func(-0.3399810436)
               + 0.6521451549 * func(+0.3399810436)
               + 0.3478548541 * func(-0.8611363116)
               + 0.3478548541 * func(+0.8611363116);
    }

    if (n == 4) {
        return   0.4786286705 * func(-0.5384693101)
               + 0.4786286705 * func(+0.5384693101)
               + 0.2369268851 * func(-0.9061798459)
               + 0.2369268851 * func(+0.9061798459)
               + 0.5688888889 * func(+0.0000000000);
    }

    throw std::runtime_error("Shouldn't be here.");
    return 0.0;
}


template<class Fn>
double gauss_legendre_integrate_a_b_(const Fn &func, double a, double b, std::size_t n) {
    double k1 = (b - a) / 2.0;
    double k2 = (b + a) / 2.0;

    auto funcNorm = [&](double x) -> double {
        return k1 * func(k1*x + k2);
    };

    return gauss_legendre_integrate_norm(funcNorm, n);
}