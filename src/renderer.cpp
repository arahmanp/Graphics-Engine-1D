#include "renderer.hpp"
#include "geometry.hpp"
#include "object.hpp"
#include <cmath>
#include <iostream>

void render(Display &display, const Camera &camera, const ObjectList &object_list) {
    for(const auto &obj : object_list.object_list) {
        if(obj.g_object == nullptr) continue;

        switch (obj.type) {
            case ObjType::Point: {
                Point *point = static_cast<Point*>(obj.g_object);
                int pixel_index = round(point->x - camera.position);
                double z_pixel = point->z;
                display.draw_pixel(pixel_index, obj.texture, z_pixel);

                break;
            }

            case ObjType::LineSegment: {
                LineSegment *line = static_cast<LineSegment*>(obj.g_object);

                double start = (line->a < line->b) ? line->a : line->b;
                double end = (line->a < line->b) ? line->b : line->a;

                int lower_bound = round(start - camera.position);
                int upper_bound = round(end - camera.position);
                int len = upper_bound - lower_bound + 1;

                for(int i = lower_bound; i <= upper_bound; i++) {
                    double t = (double)i / len;
                    double z_pixel = line->z_a + t * (line->z_b - line->z_a);
                    display.draw_pixel(i, obj.texture, z_pixel);
                }
            }
        }
    }
}

void clear_screen() {
    std::cout << "\033[2J\033[1;1H";
}