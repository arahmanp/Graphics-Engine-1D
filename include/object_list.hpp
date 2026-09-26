#pragma once

#include "object.hpp"
#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>

struct ObjectList {
    size_t size;
    std::unordered_map<std::string, size_t> name_to_index;
    std::vector<Object> object_list;

    ObjectList();
    Object& get_object(const std::string &object_name);
    void add_object(const Object &object);
    void delete_object(const std::string &object_name);
    void cleanup_dead_objects();
};