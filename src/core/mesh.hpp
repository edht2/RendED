#pragma once

#include <vector>
#include "triangle.hpp"
#include "vector3.hpp"

class Mesh {
public:
    const std::vector<Triangle> shape;
    Vector3 position;
    Vector3 rotation;

    Mesh() : shape(), position(), rotation() {
        // default constructor
    }

    Mesh(
        std::vector<Triangle> shape,
        Vector3 position,
        Vector3 rotation
    ) : shape(shape), position(position), rotation(rotation) {}

};