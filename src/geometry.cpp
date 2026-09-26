#include "geometry.hpp"

Point::Point(double x) : x(x) {}

void Point::g_translate(double distance) {
    x += distance;
}

LineSegment::LineSegment(double a, double b) : a(a), b(b) {}

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