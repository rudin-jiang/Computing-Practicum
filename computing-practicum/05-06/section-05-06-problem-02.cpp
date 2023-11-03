#include "root.hpp"
#include <cstdio>
#include <cmath>

#define ln10    2.3025850929940459
#define pi      3.1415926535897931

int main() {

    using std::log10;
    using std::sin;
    using std::cos;
    using std::exp;

    std::printf("Problem 2\n\n");

    auto f1 = [](double x) -> double { return x*x*x - x + 4.0; };
    auto f2 = [](double x) -> double { return x*x + 1.0/x/x - 10.0*x; };
    auto f3 = [](double x) -> double { return x*log10(x) - 1.0; };
    auto f4 = [](double x) -> double { return x + exp(x); };
    auto f5 = [](double x) -> double { return x/2.0 - sin(x); };

    auto df1 = [](double x) -> double { return 3.0*x*x - 1.0; };
    auto df2 = [](double x) -> double { return 2.0*x - 2.0/x/x/x - 10.0; };
    auto df3 = [](double x) -> double { return log10(x) + 1.0/ln10; };
    auto df4 = [](double x) -> double { return 1.0 + exp(x); };
    auto df5 = [](double x) -> double { return 0.5 - cos(x); };

    double a1 =   -2.0,     b1 = -1.0;
    double a2 =    9.0,     b2 = 10.0;
    double a3 =    1.0,     b3 = 10.0;
    double a4 =   -1.0,     b4 =  0.0;
    double a5 = 0.5*pi,     b5 =   pi;

    const double eps = 1.0e-10;
    
    double ntAns1 = newton_root_solver(f1, df1, a1, b1, eps);
    double ntAns2 = newton_root_solver(f2, df2, a2, b2, eps);
    double ntAns3 = newton_root_solver(f3, df3, a3, b3, eps);
    double ntAns4 = newton_root_solver(f4, df4, a4, b4, eps);
    double ntAns5 = newton_root_solver(f5, df5, a5, b5, eps);

    std::printf("Newton's method:\n");
    std::printf("ans1 = %15.10lf\n", ntAns1);
    std::printf("ans2 = %15.10lf\n", ntAns2);
    std::printf("ans3 = %15.10lf\n", ntAns3);
    std::printf("ans4 = %15.10lf\n", ntAns4);
    std::printf("ans5 = %15.10lf\n", ntAns5);
    std::printf("\n");

    double ntndAns1 = secant_root_solver(f1, a1, b1, eps);
    double ntndAns2 = secant_root_solver(f2, a2, b2, eps);
    double ntndAns3 = secant_root_solver(f3, a3, b3, eps);
    double ntndAns4 = secant_root_solver(f4, a4, b4, eps);
    double ntndAns5 = secant_root_solver(f5, a5, b5, eps);

    std::printf("Secant's method:\n");
    std::printf("ans1 = %15.10lf\n", ntndAns1);
    std::printf("ans2 = %15.10lf\n", ntndAns2);
    std::printf("ans3 = %15.10lf\n", ntndAns3);
    std::printf("ans4 = %15.10lf\n", ntndAns4);
    std::printf("ans5 = %15.10lf\n", ntndAns5);
    std::printf("\n");

    double biAns1 = bisect_root_slover(f1, a1, b1, eps);
    double biAns2 = bisect_root_slover(f2, a2, b2, eps);
    double biAns3 = bisect_root_slover(f3, a3, b3, eps);
    double biAns4 = bisect_root_slover(f4, a4, b4, eps);
    double biAns5 = bisect_root_slover(f5, a5, b5, eps);

    std::printf("Bisect's method:\n");
    std::printf("ans1 = %15.10lf\n", biAns1);
    std::printf("ans2 = %15.10lf\n", biAns2);
    std::printf("ans3 = %15.10lf\n", biAns3);
    std::printf("ans4 = %15.10lf\n", biAns4);
    std::printf("ans5 = %15.10lf\n", biAns5);
    std::printf("\n");

    return 0;
}