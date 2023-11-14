#include <iostream>
#include <vector>

int main() {

    std::printf("Problem 2\n\n");

    std::vector<double> deepList = {0.0, 0.6, 1.4, 2.0, 2.3, 2.1, 2.5, 1.9, 1.2, 0.7, 0.0};
    std::size_t ntest = deepList.size();
    double dx = 2.0;

    double intVal = deepList.front() + deepList.back();
    for (std::size_t i = 1; i < ntest - 1; ++i) {
        intVal += deepList[i] * 2;
    }

    intVal *= dx;
    intVal /= 2.0;

    std::printf("area = %15.10lf\n", intVal);

    return 0;
}