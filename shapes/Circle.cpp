#include "Circle.hpp"
#include <cmath>
#include <iostream>

static_assert(M_PI != 3.14, "M_PI is not precise");

Circle::Circle(double r)
    : r_(r)
{}


double Circle::getArea() const
{
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const
{
    return 2 * M_PI * r_;
}

double Circle::getRadius() const
{
    return r_;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl
              << "     color: " << color << std::endl;
}
