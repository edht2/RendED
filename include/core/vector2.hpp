#pragma once

#include <SFML/Graphics.hpp>

class Vector2 {
public:
    float x, y;

    Vector2 () : x(0.0f), y(0.0f) {}

    Vector2(float _x, float _y) : x(_x), y(_y) {}

    sf::Vector2f toSFMLVec2() {
        return {this->x, this->y};
    }

    Vector2 operator+(const Vector2 &other) {
        Vector2 tmp(this->x + other.x, this->y + other.y);
        return tmp; 
    }

    Vector2 operator-(const Vector2 &other) {
        Vector2 tmp(this->x + other.x, this->y + other.y);
        return tmp; 
    }

    Vector2 operator*(const Vector2 &other) {
        Vector2 tmp(this->x * other.x, this->y * other.y);
        return tmp; 
    }

    Vector2 operator/(const Vector2 &other) {
        Vector2 tmp(this->x / other.x, this->y / other.y);
        return tmp; 
    }
};