#pragma once

struct Camera {
    double position;

    Camera(double position);
    void move(double distance);
    void move_to(double destination);
};