#pragma once

struct Point {
    double x;

    Point(double x);
    void g_translate(double distance);
};

struct LineSegment {
    double a;
    double b;

    LineSegment(double a, double b);
    void g_translate(double distance);
    void g_scale(double factor);
};