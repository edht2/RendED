#pragma once

#include <SFML/Graphics.hpp>
#include "vector3.hpp"

class Vector4 {
public:
    float x, y, z, w;
    // create the 'x', 'y', 'z' and 'w' scalars
    Vector4(Vector3 vec3) : x(vec3.x), y(vec3.y), z(vec3.z), w(1.0f) {}

    Vector4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}

    Vector4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}

    Vector3 toVector3() {
        // all values should be divided by w to cast to a Vector3
        return Vector3(x / w, y / w, z / w);
    }

    sf::Vector2f toScreenSpace() {
        return sf::Vector2f(((x/w + 1) / 2) * 1600, ((y/w + 1) / 2) * 900);
    }
    // overloaded operators
    Vector4 operator*(const Vector4 &other) {
        return Vector4(x * other.x, y * other.y, z * other.z, w * other.w); 
    }

    float dot(const Vector4 &other) {
        return x * other.x + y * other.y + z * other.z + w * other.w;
    }

};