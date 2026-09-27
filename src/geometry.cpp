#include "geometry.hpp"

Point::Point(double x, double z) : x(x), z(z) {}

void Point::g_translate(double distance) {
    x += distance;
}

LineSegment::LineSegment(double a, double b, double z_a, double z_b) : a(a), b(b), z_a(z_a), z_b(z_b) {}

void LineSegment::g_translate(double distance) {
    a += distance;
    b += distance;
}

void LineSegment::g_scale(double factor) {
    double center = (a + b) / 2.0;
    double half_length = (b - a) / 2.0 * factor;
    a = center - half_length;
    b = center + half_length;
}