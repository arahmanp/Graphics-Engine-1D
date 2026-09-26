#include "object.hpp"
#include "geometry.hpp"

void Object::translate(double distance) {
    switch (type) {
        case ObjType::Point:
            static_cast<Point*>(g_object)->g_translate(distance);
            break;
        
        case ObjType::LineSegment:
            static_cast<LineSegment*>(g_object)->g_translate(distance);
    }
}

void Object::scale(double factor) {
    switch (type) {
        case ObjType::Point:
            break;

        case ObjType::LineSegment:
            static_cast<LineSegment*>(g_object)->g_scale(factor);
    }
}

Object create_point(std::string name, double x, char texture) {
    Point *point = new Point(x);

    Object obj = {
        name,
        ObjType::Point,
        texture,
        static_cast<void*>(point),
    };

    return obj;
}

Object create_line_segment(std::string name, double a, double b, char texture) {
    LineSegment *line = new LineSegment(a, b);

    Object obj = {
        name,
        ObjType::LineSegment,
        texture,
        static_cast<void*>(line),
    };

    return obj;
}