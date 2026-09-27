#include "display.hpp"
#include "common.hpp"
#include <iostream>

Display::Display(int size, char background) : size(size), background(background), 
    display(size, background), z_buffer(size, MAX_DEPTH) {}

void Display::draw_pixel(int index, char texture, double depth) {
    if(0 <= index && index < size) {
        if(depth < z_buffer[index]) {
            display[index] = texture;
            z_buffer[index] = depth;
        }
    }
}

void Display::print() {
    for(const auto &pixel : display) {
        std::cout << pixel;
    }
    std::cout << '\n';
}

void Display::clear() {
    for(int i = 0; i < size; i++) {
        display[i] = background;
        z_buffer[i] = MAX_DEPTH;
    }
}