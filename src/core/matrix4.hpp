#pragma once

#include "vector3.hpp"
#include <array>
#include <cmath> // for tan and pi

class Matrix4 {
public:
    std::array<float, 16> elements;

    Matrix4() {
        elements.fill(0.0f);
        elements[0 + 0 * 4] = 1.0f;
        elements[1 + 1 * 4] = 1.0f;
        elements[2 + 2 * 4] = 1.0f;
        elements[3 + 3 * 4] = 1.0f;
    }

    Matrix4(const std::array<float, 16>& data) : elements(data) {}

    static Matrix4 perspective(float fov_y, float aspect_ratio, float near_z, float far_z) {
        Matrix4 tmp;
        tmp.elements.fill(0.0f);

        float tan_half_fov_y = std::tan(fov_y / 2.0f * (M_PI / 180.0f)); // Convert degrees to radians
        float f = 1.0f / tan_half_fov_y;

        tmp.elements[0 + 0 * 4] = f / aspect_ratio;
        tmp.elements[1 + 1 * 4] = f;
        tmp.elements[2 + 2 * 4] = (far_z + near_z) / (near_z - far_z);
        tmp.elements[3 + 2 * 4] = -1.0f; // For perspective divide
        tmp.elements[2 + 3 * 4] = (2.0f * far_z * near_z) / (near_z - far_z);

        return tmp;
    }

    // Add matrix multiplication (A * B)
    Matrix4 operator*(const Matrix4& other) const {
        Matrix4 tmp;
        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 4; ++col) {
                float sum = 0.0f;
                for (int i = 0; i < 4; ++i) {
                    sum += this->elements[row + i * 4] * other.elements[i + col * 4];
                }
                tmp.elements[row + col * 4] = sum;
            }
        }
        return tmp;
    }

    // Add vector transformation (Matrix * Vector)
    Vector3 operator*(const Vector3& vec) const {
        // vec is assumed as a position so we're using homogenous coords
        float x = elements[0] * vec.x + elements[4] * vec.y + elements[8] * vec.z + elements[12];
        float y = elements[1] * vec.x + elements[5] * vec.y + elements[9] * vec.z + elements[13];
        float z = elements[2] * vec.x + elements[6] * vec.y + elements[10] * vec.z + elements[14];
        float w = elements[3] * vec.x + elements[7] * vec.y + elements[11] * vec.z + elements[15];

        // Perform perspective divide if w is not 1 (for perspective projection)
        if (w != 0.0f && w != 1.0f) {
            return Vector3(x / w, y / w, z / w);
        }
        return Vector3(x, y, z);
    }

};