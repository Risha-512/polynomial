#include <iostream>
#include "polynomial.h"

int main()
{
    // test
    auto p1 = Polynomial(0, 3) + Polynomial(2, 2) * Polynomial(3, 5) - Polynomial(5, 4);

    std::cout << "Polynomial: " + p1.to_string() << std::endl << "Derivative: " + p1.derivative().to_string();

    return 0;
}
