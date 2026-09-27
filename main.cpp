#include "camera.hpp"
#include "display.hpp"
#include "object.hpp"
#include "object_list.hpp"
#include "renderer.hpp"
#include <chrono>
#include <thread>

int main() {
    // Setting up environment
    Display display(20);
    Camera camera(0.0);
    ObjectList obj_list;

    obj_list.add_object(create_line_segment("line", 1, 3, 5.0, 5.0, '#'));
    obj_list.add_object(create_point("point", 2, 7.0, '@'));

    render(display, camera, obj_list);
    display.print();
    display.clear();

    return 0;
}