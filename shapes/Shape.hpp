#pragma once
#include <iostream>

enum class Color : unsigned char {
    White,
    Red,
    Blue,
};

std::ostream& operator<<(std::ostream& os, Color c);
class Shape {
protected:
    Color color = Color::White;

public:
    Shape(Color c)
        : color(c) {}
    Shape() {}
    Shape(Shape const& sh)
        : color(sh.color) {}
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
};
