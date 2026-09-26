#pragma once

#include <vector>

struct Display {
    int size;
    char background;
    std::vector<char> display;

    Display(int size, char background = ' ');
    void draw_pixel(int index, char texture);
    void print();
    void clear();
};