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