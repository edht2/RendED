#include "render/object_projection.hpp"
#include "core/vector4.hpp"
#include <vector>

#include <cmath>

sf::Color greyScale(float scalar) {
    scalar += 1;
    scalar *= 127;
    return sf::Color(scalar, scalar, scalar);
}

sf::VertexArray objectProjection(Object* _object, Matrix4x4 projection_matrix, float ticks) {
    // projects an object and creates primative with projected points

    Object object = *_object;

    Matrix4x4 view_matrix;
    // identity matrix (view matrix not implemented yet)

    sf::VertexArray vertex_arr(sf::Triangles, object.mesh.size() * 3);
    // SFML vertex array used to store and then plot the primitives 

    Matrix4x4 final_matrix = projection_matrix * view_matrix * object.model_matrix;
    // final matrix it a combination of the projection, view and model matricies

    for (size_t i = 0; i < object.mesh.size(); ++i) {

        for (size_t j = 0; j < 3; ++j) {

            vertex_arr[j + i * 3].position = (final_matrix * Vector4(object.mesh[i].points[j])).toScreenSpace();
            vertex_arr[j + i * 3].color = greyScale(object.mesh[i].normal.dot(Vector3(sin(ticks), cos(ticks), 0)));

        }

    }

    return vertex_arr;
}