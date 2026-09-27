#pragma once

#include <vector>

struct Display {
    int size;
    char background;
    std::vector<char> display;
    std::vector<double> z_buffer;

    Display(int size, char background = ' ');
    void draw_pixel(int index, char texture, double depth);
    void print();
    void clear();
};