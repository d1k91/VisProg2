#include "areacalculator.h"
#include <cmath>

double AreaCalculator::square(double side) {
    return side * side;
}

double AreaCalculator::rectangle(double length, double width) {
    return length * width;
}

double AreaCalculator::parallelogram(double base, double height) {
    return base * height;
}

double AreaCalculator::rhombus(double diagonal1, double diagonal2) {
    return (diagonal1 * diagonal2) / 2;
}

double AreaCalculator::triangle(double base, double height) {
    return (base * height) / 2;
}

double AreaCalculator::trapezoid(double base1, double base2, double height) {
    return ((base1 + base2) * height) / 2;
}

double AreaCalculator::circle(double radius) {
    return M_PI * radius * radius;
}

double AreaCalculator::sector(double radius, double angle) {
    return (M_PI * radius * radius * angle) / 360;
}
