#ifndef AREACALCULATORH
#define AREACALCULATORH

class AreaCalculator {
public:
    static double square(double side);
    static double rectangle(double length, double width);
    static double parallelogram(double base, double height);
    static double rhombus(double diagonal1, double diagonal2);
    static double triangle(double base, double height);
    static double trapezoid(double base1, double base2, double height);
    static double circle(double radius);
    static double sector(double radius, double angle);
};

#endif // AREACALCULATORH
