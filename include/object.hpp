#pragma once

#include <string>
#include "common.hpp"

struct Object {
    std::string name;
    ObjType type;
    char texture;
    void *g_object;

    void translate(double distance);
    void scale(double factor);
};

Object create_point(std::string name, double x, char texture);
Object create_line_segment(std::string name, double a, double b, char texture);