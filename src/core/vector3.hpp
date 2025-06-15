#pragma once

class Vector3 {
public:
    float x, y, z;
    // create the x, y, z scalars

    Vector3() : x(0.0f), y(0.0f), z(0.0f) {
        // default contructor
    }

    Vector3(float x, float y, float z) : x(x), y(y), z(z) {     
        //initialise the values
    }

    // overloaded operators
    Vector3 operator+(const Vector3 &other) {
        Vector3 tmp(this->x + other.x, this->y + other.y, this->z + other.z);
        return tmp; 
    }

    Vector3 operator-(const Vector3 &other) {
        Vector3 tmp(this->x - other.x, this->y - other.y, this->z - other.z);
        return tmp; 
    }

    Vector3 operator*(const Vector3 &other) {
        Vector3 tmp(this->x * other.x, this->y * other.y, this->z * other.z);
        return tmp; 
    }

    Vector3 operator/(const Vector3 &other) {
        Vector3 tmp(this->x / other.x, this->y / other.y, this->z / other.z);
        return tmp; 
    }

    float dot(const Vector3 &other) {
        return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
    }

    Vector3 cross(const Vector3 &other) {
        Vector3 tmp(this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x);
        return tmp;
    }

};