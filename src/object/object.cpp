#include "object/object.hpp"
#include <iostream>


void Object::constructModelMatrix() {
    auto scale_matrix = Matrix4x4().scale(scale);
    auto translate_matrix = Matrix4x4().translate(position);
    
    model_matrix = translate_matrix * scale_matrix;
}

void Object::print() {
    // purely for debugging!
    for (auto& tri : mesh) {
        for (auto& point : tri.points) {
            std::cout << point.x << " " << point.y << " " << point.z << std::endl;
        }
    }
};