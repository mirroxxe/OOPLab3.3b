#include <iostream>
#include "Money.h"

int main() {
    Money m1, m2;

    std::cout << "Enter the first amount of money:" << std::endl;
    std::cin >> m1;
    std::cout << "Enter the second amount of money:" << std::endl;
    std::cin >> m2;

    std::cout << "First amount: " << m1 << std::endl;
    std::cout << "Second amount: " << m2 << std::endl;

    Money sum = m1 + m2;
    std::cout << "Sum: " << sum << std::endl;

    try {
        Money divided = m1 / 3;
        std::cout << "Result of dividing the first amount by 3: " << divided << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}