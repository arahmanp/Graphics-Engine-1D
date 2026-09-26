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