#pragma once

#include <vector>
#include "core/triangle.hpp"
#include "core/vector3.hpp"
#include "core/matrix4x4.hpp"

class Object {
public:
    const std::vector<Triangle> mesh;
    Matrix4x4 model_matrix;

    Vector3 position;
    Vector3 rotation;
    float scale;

    Object() : mesh(), position(), scale(0.0f) {}

    Object(std::vector<Triangle> _mesh) : mesh(_mesh), position(), scale(0.0f) {}

    void constructModelMatrix();

    void print();
};