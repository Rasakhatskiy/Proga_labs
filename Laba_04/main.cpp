#include <iostream>
#include "Formula_07.h"
#include "Formula_09.h"

int main() {
    double eps, x;
    std::cout << "Enter X : ";
    std::cin >> x;
    std::cout << "Enter Eps : ";
    std::cin >> eps;

    std::cout << "Result = " << Formula_09::Start(x, eps) << std::endl;
    system("pause");
    return 0;
}
