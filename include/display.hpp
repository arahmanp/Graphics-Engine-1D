#pragma once

#include <cstddef>
#include <vector>

struct Display {
    size_t size;
    char background;
    std::vector<char> display;

    Display(size_t size, char background = ' ');
    void draw_pixel(size_t index, char texture);
    void print();
    void clear();
};