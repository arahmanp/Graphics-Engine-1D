#include "object_list.hpp"
#include "geometry.hpp"
#include "object.hpp"
#include <cstddef>
#include <string>
#include <utility>

ObjectList::ObjectList() : size(0) {}

Object& ObjectList::get_object(const std::string &object_name) {
    return object_list.at(name_to_index.at(object_name));
}

void ObjectList::add_object(const Object &object) {
    if(name_to_index.contains(object.name)) return;

    object_list.push_back(object);
    name_to_index[object.name] = size;
    size++;
}

void ObjectList::delete_object(const std::string &object_name) {
    if(!name_to_index.contains(object_name)) return;

    size_t object_index = name_to_index[object_name];
    Object &deleted_object = object_list[object_index];

    if(deleted_object.g_object == nullptr) return;

    switch (deleted_object.type) {
        case ObjType::Point: {
            Point *point = static_cast<Point*>(deleted_object.g_object);
            delete point;
            break;
        }

        case ObjType::LineSegment: {
            LineSegment *line = static_cast<LineSegment*>(deleted_object.g_object);
            delete line;
            break;
        }
    }

    deleted_object.g_object = nullptr;
}

void ObjectList::cleanup_dead_objects() {
    size_t i = 0;
    while(i < size) {
        if(object_list[i].g_object == nullptr) {
            name_to_index.erase(object_list[i].name);

            if(i != size - 1) {
                object_list[i] = std::move(object_list.back());

                name_to_index[object_list[i].name] = i;
            }

            object_list.pop_back();

            size--;
        } else {
            i++;
        }
    }
}