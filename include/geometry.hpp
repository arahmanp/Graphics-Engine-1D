#pragma once

struct Point {
    double x;
    double z;

    Point(double x, double z);
    void g_translate(double distance);
};

struct LineSegment {
    double a;
    double b;
    double z_a;
    double z_b;

    LineSegment(double a, double b, double z_a, double z_b);
    void g_translate(double distance);
    void g_scale(double factor);
};