#include "render/object_projection.hpp"
#include "core/vector4.hpp"
#include <iostream>

sf::VertexArray objectProjection(Object object, Matrix4x4 projection_matrix) {
    // projects an object and creates primative with projected points

    sf::VertexArray vertex_arr(sf::Triangles, object.mesh.size() * 3);

    for (size_t i = 0; i < object.mesh.size(); ++i) {
        vertex_arr[0+i*3].position = ((projection_matrix * Matrix4x4() * object.model_matrix) * Vector4(object.mesh[i].points[0])).toScreenSpace();
        vertex_arr[1+i*3].position = ((projection_matrix * Matrix4x4() * object.model_matrix) * Vector4(object.mesh[i].points[1])).toScreenSpace();
        vertex_arr[2+i*3].position = ((projection_matrix * Matrix4x4() * object.model_matrix) * Vector4(object.mesh[i].points[2])).toScreenSpace();
        // add view matrix here later!!!
        
        vertex_arr[0+i*3].color = sf::Color::Red;
        vertex_arr[1+i*3].color = sf::Color::Green;
        vertex_arr[2+i*3].color = sf::Color::Blue;
    }
    return vertex_arr;
}