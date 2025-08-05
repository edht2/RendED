#pragma once

#include "vector3.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Triangle {
public:
    std::array<Vector3, 3> points;
    Vector3 normal;
    sf::Color colour;
    // texture coordinates

    Triangle() : points({Vector3(), Vector3(), Vector3()}), colour(sf::Color::White) {
        // default constructor, default colour is white
    };

    Triangle(Vector3 a, Vector3 b, Vector3 c) : points({a, b, c}), colour(sf::Color::White) {
        // contructor with args
        Vector3 A = points[1] - points[0];
        Vector3 B = points[2] - points[0];

        normal = A.cross(B).normalised();
        // ||A x B|| = Normal vector!
    };


    Triangle(Vector3 a, Vector3 b, Vector3 c, sf::Color colour) : points({a, b, c}), colour(colour) {
        // contructor with args
    };

    Triangle operator+(const Triangle &other) {
        return Triangle(
            this->points[0] + other.points[0],
            this->points[1] + other.points[1],
            this->points[2] + other.points[2],
            this->colour
        );
    }

    Triangle operator-(const Triangle &other) {
        return Triangle(
            this->points[0] - other.points[0],
            this->points[1] - other.points[1],
            this->points[2] - other.points[2],
            this->colour
        );
    }

    Triangle operator*(const Triangle &other) {
        return Triangle(
            this->points[0] * other.points[0],
            this->points[1] * other.points[1],
            this->points[2] * other.points[2],
            this->colour
        ); 
    }

    Triangle operator/(const Triangle &other) {
        return Triangle(
            this->points[0] / other.points[0],
            this->points[1] / other.points[1],
            this->points[2] / other.points[2],
            this->colour
        );
    }

};