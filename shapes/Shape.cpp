#include "Shape.hpp"


void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}
std::ostream& operator<<(std::ostream& os, Color c) {
    if (c == Color::White) {
        os << "White";
    } else if (c == Color::Red) {
        os << "Red";
    } else {
            os << "Blue";
        }
        return os;
}