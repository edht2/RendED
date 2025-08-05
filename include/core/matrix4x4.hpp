#pragma once

#include <array>
#include <cmath>
#include <iostream>

#include "core/vector4.hpp"
#include "core/vector3.hpp"

class Matrix4x4 {

// I'm using this to show positions: column + row * n(rows)
// matrix[3 + 2 * 4] is col 3, row 4

public:

    std::array<float, 16> matrix;

    Matrix4x4() {
        matrix.fill(0.0f);
        // initialise matrix with 0s

        matrix[0 + 0 * 4] = 1.0f;
        matrix[1 + 1 * 4] = 1.0f;
        matrix[2 + 2 * 4] = 1.0f;
        matrix[3 + 3 * 4] = 1.0f;
        // empty matrix (nothing happens when you multiply by it)
    }

    Matrix4x4(float a) {
        matrix.fill(0.0f);
        // initialise matrix with 0s

        matrix[0 + 0 * 4] = a;
        matrix[1 + 1 * 4] = a;
        matrix[2 + 2 * 4] = a;
        matrix[3 + 3 * 4] = a;
    }

    Matrix4x4(std::array<float, 16> matrix) : matrix(matrix) {}

    Vector4 operator*(const Vector4& other) {
        if (other.x == 0.f) {
            other.x == 0.01f;
        }
        if (other.y == 0.f) {
            other.y == 0.01f;
        } // for division by zero preventation

        Vector4 tmp (
            matrix[0 + 0 * 4] * other.x + matrix[1 + 0 * 4] * other.y + matrix[2 + 0 * 4] * other.z + matrix[3 + 0 * 4] * other.w,
            matrix[0 + 1 * 4] * other.x + matrix[1 + 1 * 4] * other.y + matrix[2 + 1 * 4] * other.z + matrix[3 + 1 * 4] * other.w,
            matrix[0 + 2 * 4] * other.x + matrix[1 + 2 * 4] * other.y + matrix[2 + 2 * 4] * other.z + matrix[3 + 2 * 4] * other.w,
            matrix[0 + 3 * 4] * other.x + matrix[1 + 3 * 4] * other.y + matrix[2 + 3 * 4] * other.z + matrix[3 + 3 * 4] * other.w
        );
        return tmp;
    }

    Matrix4x4 operator*(const Matrix4x4& other) {
        Matrix4x4 tmp(0.f);

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    tmp.matrix[j + i * 4] += matrix[k + i * 4] * other.matrix[j + k * 4];
                }
            }
        }
        return tmp;

    }

    Matrix4x4 perspective(float near, float far, float fovy, float aspect_ratio) {
        // ┌                                                   ┐   ┌   ┐                  ┌     ┐
        // │ 1/α*tan(θ/2)       0            0           0     │   │ x │                  │ x/w │ x is x pixle
        // │       0       1/tan(θ/2)        0           0     │ * │ y │ = Screen Space → │ y/w │ y is y pixle
        // │       0            0       -(f+n/f-n)  -(2fn/f-n) │   │ z │                  │ z/w │ z is order to render this vertex
        // │       0            0           -1           0     │   │ w │                  └     ┘ NOTE : w is removed (cast to Vector3)
        // └                                                   ┘   └   ┘                  

        // α = aspect ratio = width / height
        // θ = fovy
        // f = far plane
        // n = near plane

        Matrix4x4 tmp;

        float a = fovy * M_PI / 180;

        tmp.matrix[0 + 0 * 4] = 1 / aspect_ratio * tan(a / 2);
        tmp.matrix[1 + 1 * 4] = 1 / tan(a / 2);
        tmp.matrix[2 + 2 * 4] = -(far + near / far - near);
        tmp.matrix[2 + 3 * 4] = -1;
        tmp.matrix[3 + 2 * 4] = -(2 * far * near / far - near);

        return tmp;
    }

    Matrix4x4 scale(float scale) {
        // ┌                                ┐   
        // │    S       0       0      0    │ 
        // │    0       S       0      0    │    Where 'S' is a scaling float
        // │    0       0       S      0    │
        // │    0       0       0      1    │ 
        // └                                ┘                    
        Matrix4x4 tmp(0.f);

        tmp.matrix[0 + 0 * 4] = scale;
        tmp.matrix[1 + 1 * 4] = scale;
        tmp.matrix[2 + 2 * 4] = scale;
        tmp.matrix[3 + 3 * 4] = 1;

        return tmp;
    }

    Matrix4x4 translate(Vector3 offset) {
        // ┌                                ┐   
        // │    0       0       0     T.x   │ 
        // │    0       0       0     T.y   │    Where 'S' is a scaling float
        // │    0       0       0     T.z   │
        // │    0       0       0      1    │ 
        // └                                ┘   
        Matrix4x4 tmp;

        tmp.matrix[3 + 0 * 4] = offset.x;
        tmp.matrix[3 + 1 * 4] = offset.y;
        tmp.matrix[3 + 2 * 4] = offset.z;

        return tmp;
    }

    void print() {
        for (size_t i = 0; i < 4; ++i) {
            for (size_t j = 0; j < 4; ++j) {
                std::cout << "    " << matrix[j + i * 4];
            }
            std::cout << std::endl;
        }
    }

    // also implement euler angle roation / quaternions

};