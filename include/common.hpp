#pragma once

#include <limits>

const double MAX_DEPTH = std::numeric_limits<double>::infinity();

enum class ObjType {
    Point,
    LineSegment,
};
