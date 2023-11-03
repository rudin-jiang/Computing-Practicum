#pragma once

#include <cmath>
#include <cstddef>
#include <cassert>
#include <exception>
#include <stdexcept>

// // old version
// using fp = double (*)(double);
// double bisect_root_slover(fp func, double la, double rb, double eps);
// double newton_root_solver(fp func, double la, double rb, double eps);
// double newton_root_solver(fp func, fp dfunc, double la, double rb, double eps);


template<class fn>
double bisect_root_slover(const fn &func, double la, double rb, double eps) {
    if (la > rb) throw std::invalid_argument("interval representation error.");
    if (eps < 0.0) throw std::invalid_argument("negative eps.");

    std::size_t kMax = std::size_t(std::log2((rb - la) / eps) + 1);
    double ak = la, bk = rb;
    double fak = func(ak);
    double fbk = func(bk);

    double xk = 0.0;
    double fxk = 0.0;

    for (std::size_t k = 0; k < kMax; ++k) {
        xk = (ak + bk) / 2.0;
        fxk = func(xk);

        // TODO: may be possible to set an eps
        if (fxk == 0.0) return xk;

        if (fbk * fxk < 0.0) {
            ak = xk;
            fak = fxk;
        } 
        else {
            bk = xk;
            fbk = fxk;
        }
    }

    return xk;
}

template<class fn1, class fn2>
double newton_root_solver(const fn1 &func, const fn2 &dfunc, double x0, double eps) {
    if (eps < 0.0) throw std::invalid_argument("negative eps.");

    double xk_0 = x0;
    double xk_1 = xk_0;

    do {
        double vfxk = func(xk_1);
        double dfxk = dfunc(xk_1);
        double xk_2 = xk_1 - vfxk / dfxk;

        xk_0 = xk_1;
        xk_1 = xk_2;

    } while(std::abs(xk_0 - xk_1) > eps);

    return xk_1;
}

template<class fn>
double secant_root_solver(const fn &func, double x0, double eps) {
    if (eps < 0.0) throw std::invalid_argument("negative eps.");

    double xk_0 = x0;
    double xk_1 = x0 + 0.1;

    do {
        double fxk_0 = func(xk_0);
        double fxk_1 = func(xk_1);
        double xk_2 = xk_1 - fxk_1 * (xk_1 - xk_0) / (fxk_1 - fxk_0);

        xk_0 = xk_1;
        xk_1 = xk_2;

    } while (std::abs(xk_0 - xk_1) > eps);

    return xk_1;
}

template<class fn1, class fn2>
double newton_root_solver(const fn1 &func, const fn2 &dfunc, double la, double rb, double eps) {
    if (la > rb) throw std::invalid_argument("interval representation error.");
    if (eps < 0.0) throw std::invalid_argument("negative eps.");

    double fa = func(la);
    double fb = func(rb);

    double dfa = dfunc(la);
    double dfb = dfunc(rb);
    double ddf = dfb - dfa;     // sign of second order derivative

    double xk_0 = (ddf * fa > 0.0 ? la : rb);
    double xk_1 = xk_0;

    do {
        double vfxk = func(xk_1);
        double dfxk = dfunc(xk_1);
        double xk_2 = xk_1 - vfxk / dfxk;

        xk_0 = xk_1;
        xk_1 = xk_2;

    } while(std::abs(xk_0 - xk_1) > eps);

    // TODO: out of range check
    if (xk_1 < la || xk_1 > rb) { }

    return xk_1;
}

template<class fn>
double secant_root_solver(const fn &func, double la, double rb, double eps) {
    if (la > rb) throw std::invalid_argument("interval representation error.");
    if (eps < 0.0) throw std::invalid_argument("negative eps.");

    double fa = func(la);
    double fb = func(rb);
    double fm = func((la+rb) / 2);

    // sign of second order derivative
    double ddf = (fa + fb) / 2.0 - fm;

    double xk_0 = 0.0;
    double xk_1 = 0.0;
    double dlen = (rb - la) / 10.0;

    xk_0 = (ddf * fa > 0.0 ? la : rb);
    xk_1 = (ddf * fa > 0.0 ? la + dlen : rb - dlen);

    do {
        double fxk_0 = func(xk_0);
        double fxk_1 = func(xk_1);
        double xk_2 = xk_1 - fxk_1 * (xk_1 - xk_0) / (fxk_1 - fxk_0);

        xk_0 = xk_1;
        xk_1 = xk_2;

    } while (std::abs(xk_0 - xk_1) > eps);

    // TODO: out of range check
    if (xk_1 < la || xk_1 > rb) { }

    return xk_1;
}

