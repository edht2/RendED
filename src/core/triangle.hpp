#pragma once

#include "vector3.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Triangle {
public:
    std::array<Vector3, 3> points;
    sf::Color colour;

    Triangle() : points({Vector3(), Vector3(), Vector3()}), colour(sf::Color::White) {
        // default constructor, default colour is white
    };

    Triangle(Vector3 a, Vector3 b, Vector3 c, sf::Color colour) : points({a, b, c}), colour(colour) {
        // contructor with args
    };

    Triangle operator+(const Triangle &other) {
        Triangle tmp(
            this->points[0] + other.points[0],
            this->points[1] + other.points[1],
            this->points[2] + other.points[2],
            sf::Color::White
        );
        return tmp; 
    }

    Triangle operator-(const Triangle &other) {
        Triangle tmp(
            this->points[0] - other.points[0],
            this->points[1] - other.points[1],
            this->points[2] - other.points[2],
            sf::Color::White
        );
        return tmp; 
    }

    Triangle operator*(const Triangle &other) {
        Triangle tmp(
            this->points[0] * other.points[0],
            this->points[1] * other.points[1],
            this->points[2] * other.points[2],
            sf::Color::White
        );
        return tmp; 
    }

    Triangle operator/(const Triangle &other) {
        Triangle tmp(
            this->points[0] / other.points[0],
            this->points[1] / other.points[1],
            this->points[2] / other.points[2],
            sf::Color::White
        );
        return tmp; 
    }

};