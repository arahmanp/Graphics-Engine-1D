#include "display.hpp"
#include <cstddef>
#include <iostream>

Display::Display(size_t size, char background) : size(size), background(background), 
    display(size, background) {}

void Display::draw_pixel(size_t index, char texture) {
    if(index < size) {
        display[index] = texture;
    }
}

void Display::print() {
    for(const auto &pixel : display) {
        std::cout << pixel;
    }
    std::cout << '\n';
}

void Display::clear() {
    for(auto &pixel : display) {
        pixel = background;
    }
}