#include "camera.hpp"
#include "display.hpp"
#include "object.hpp"
#include "object_list.hpp"
#include "renderer.hpp"

int main() {
    Display display(15, '.');
    Camera camera(0.0);
    ObjectList obj_list;

    obj_list.add_object(create_line_segment("Line_B", 2.0, 10.0, 10.0, 2.0, '@'));
    obj_list.add_object(create_line_segment("Line_A", 2.0, 10.0, 2.0, 10.0, '#'));

    display.clear();
    render(display, camera, obj_list);
    display.print();

    return 0;
}