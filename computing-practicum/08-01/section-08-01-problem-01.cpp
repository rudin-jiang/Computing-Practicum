#include "gauss-legendre.hpp"
#include <cstdio>
#include <iostream>
#include <cmath>

#define pi  3.1415926535897931
#define ln2 0.6931471805599453

int main() {
    using std::log;
    using std::sin;
    using std::cos;

    std::printf("Problem 1\n\n");

    auto func1 = [](double x) -> double { return log(1.0 - x) / x; };
    auto func2 = [](double x) -> double { return log(1.0 - x) * log(x); };
    auto func3 = [](double x) -> double { return log(cos(x)); };
    auto func4 = [](double x) -> double { return (sin(x) + sin(1.0/x)) / x; };
    auto func5 = [](double x) -> double { return sin(x*x) + sin(1.0/x/x) / x / x; };

    double a1 = 0.0,  b1 =  1.0;
    double a2 = 0.0,  b2 =  1.0;
    double a3 = 0.0,  b3 = pi/2;
    double a4 = 0.0,  b4 =  1.0;
    double a5 = 0.0,  b5 =  1.0;

    double acc1  = - pi * pi / 6.0;
    double acc2  = 2.0 - pi * pi / 6.0;
    double acc3  = - pi * ln2 / 2.0;
    double acc4  = pi / 2.0;
    double acc5  = std::sqrt(pi / 2.0) / 2.0;

    std::printf("Problem 1.1\n");
    
    double ans11 = gauss_legendre_integrate_a_b_(func1, a1, b1, 1);
    double ans12 = gauss_legendre_integrate_a_b_(func1, a1, b1, 2);
    double ans13 = gauss_legendre_integrate_a_b_(func1, a1, b1, 3);
    double ans14 = gauss_legendre_integrate_a_b_(func1, a1, b1, 4);
    
    std::printf("Gauss-Legendre n = 1 :  %15.10lf\n", ans11);
    std::printf("Gauss-Legendre n = 2 :  %15.10lf\n", ans12);
    std::printf("Gauss-Legendre n = 3 :  %15.10lf\n", ans13);
    std::printf("Gauss-Legendre n = 4 :  %15.10lf\n", ans14);
    std::printf("Accuracy value       :  %15.10lf\n", acc1);
    std::printf("\n");


    std::printf("Problem 1.2\n");
    
    double ans21 = gauss_legendre_integrate_a_b_(func2, a2, b2, 1);
    double ans22 = gauss_legendre_integrate_a_b_(func2, a2, b2, 2);
    double ans23 = gauss_legendre_integrate_a_b_(func2, a2, b2, 3);
    double ans24 = gauss_legendre_integrate_a_b_(func2, a2, b2, 4);
    
    std::printf("Gauss-Legendre n = 1 :  %15.10lf\n", ans21);
    std::printf("Gauss-Legendre n = 2 :  %15.10lf\n", ans22);
    std::printf("Gauss-Legendre n = 3 :  %15.10lf\n", ans23);
    std::printf("Gauss-Legendre n = 4 :  %15.10lf\n", ans24);
    std::printf("Accuracy value       :  %15.10lf\n", acc2);
    std::printf("\n");

    
    std::printf("Problem 1.3\n");
    
    double ans31 = gauss_legendre_integrate_a_b_(func3, a3, b3, 1);
    double ans32 = gauss_legendre_integrate_a_b_(func3, a3, b3, 2);
    double ans33 = gauss_legendre_integrate_a_b_(func3, a3, b3, 3);
    double ans34 = gauss_legendre_integrate_a_b_(func3, a3, b3, 4);
    
    std::printf("Gauss-Legendre n = 1 :  %15.10lf\n", ans31);
    std::printf("Gauss-Legendre n = 2 :  %15.10lf\n", ans32);
    std::printf("Gauss-Legendre n = 3 :  %15.10lf\n", ans33);
    std::printf("Gauss-Legendre n = 4 :  %15.10lf\n", ans34);
    std::printf("Accuracy value       :  %15.10lf\n", acc3);
    std::printf("\n");

    
    std::printf("Problem 1.4\n");
    
    double ans41 = gauss_legendre_integrate_a_b_(func4, a4, b4, 1);
    double ans42 = gauss_legendre_integrate_a_b_(func4, a4, b4, 2);
    double ans43 = gauss_legendre_integrate_a_b_(func4, a4, b4, 3);
    double ans44 = gauss_legendre_integrate_a_b_(func4, a4, b4, 4);
    
    std::printf("Gauss-Legendre n = 1 :  %15.10lf\n", ans41);
    std::printf("Gauss-Legendre n = 2 :  %15.10lf\n", ans42);
    std::printf("Gauss-Legendre n = 3 :  %15.10lf\n", ans43);
    std::printf("Gauss-Legendre n = 4 :  %15.10lf\n", ans44);
    std::printf("Accuracy value       :  %15.10lf\n", acc4);
    std::printf("\n");

    
    std::printf("Problem 1.5\n");
    
    double ans51 = gauss_legendre_integrate_a_b_(func5, a5, b5, 1);
    double ans52 = gauss_legendre_integrate_a_b_(func5, a5, b5, 2);
    double ans53 = gauss_legendre_integrate_a_b_(func5, a5, b5, 3);
    double ans54 = gauss_legendre_integrate_a_b_(func5, a5, b5, 4);
    
    std::printf("Gauss-Legendre n = 1 :  %15.10lf\n", ans51);
    std::printf("Gauss-Legendre n = 2 :  %15.10lf\n", ans52);
    std::printf("Gauss-Legendre n = 3 :  %15.10lf\n", ans53);
    std::printf("Gauss-Legendre n = 4 :  %15.10lf\n", ans54);
    std::printf("Accuracy value       :  %15.10lf\n", acc5);
    std::printf("\n");

    return 0;
}