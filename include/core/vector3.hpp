#pragma once
#include <cmath>
#include "core/vector2.hpp"

class Vector3 {
public:
    float x, y, z;
    // create the 'x', 'y', 'z' scalars

    Vector3() : x(0.0f), y(0.0f), z(0.0f) {
        // default contructor
    }

    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {     
        // initialise the values
    }

    float length() {
        return sqrt(x * x + y * y + z * z);
    }

    Vector3 normalised() {
        // returns a normalised version of the Vector3
        return Vector3(x / length(), y / length(), z / length());
    }

    // overloaded operators
    Vector3 operator+(const Vector3 &other) {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 operator-(const Vector3 &other) {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3 operator*(const Vector3 &other) {
        return Vector3(x * other.x, y * other.y, z * other.z);
    }

    Vector3 operator/(const Vector3 &other) {
        return Vector3(x / other.x, y / other.y, z / other.z);
    }

    float dot(const Vector3 &other) const {
        return (x * other.x) + (y * other.y) + (z * other.z);
    }

    Vector3 cross(const Vector3 &other) {
        return Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }

    Vector2 toVector2() {
        return Vector2(x, y);
        // leaves z coordionate
    }
};




