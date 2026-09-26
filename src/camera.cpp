#include "camera.hpp"

Camera::Camera(double position) : position(position) {}

void Camera::move(double distance) {
    position += distance;
}

void Camera::move_to(double destination) {
    position = destination;
}