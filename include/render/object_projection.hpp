#include <SFML/Graphics.hpp>
#include "object/object.hpp"
#include "core/matrix4x4.hpp"

sf::VertexArray objectProjection(Object* _object, Matrix4x4 projection_matrix, float ticks);