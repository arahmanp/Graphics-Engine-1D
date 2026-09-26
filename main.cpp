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

    // Create some line segments
    for(int i = 2; i <= 200; i += 6) {
        obj_list.add_object(create_line_segment(std::to_string(i), i, i + 3, '#'));
    }
    obj_list.add_object(create_line_segment("last_line", 280, 300, '%'));
    
    // Setting up camera movement
    double distance = 1.0;

    // Execute camera movement, create a cool animation!
    while(1) {
        clear_screen();

        render(display, camera, obj_list);
        display.print();
        display.clear();

        camera.move(distance);

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}