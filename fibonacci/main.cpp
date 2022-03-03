#include <iostream>
#include "fibonacci.hpp"

int main() {
    // std::cout << fibonacci_iterative(45) << "\n";
  int result = fibonacci_recursive(25);
    std::cout << result << "\n";

    return 0;
}
