#include "display.hpp"
#include <iostream>

Display::Display(int size, char background) : size(size), background(background), 
    display(size, background) {}

void Display::draw_pixel(int index, char texture) {
    if(0 <= index && index < size) {
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