#include "core/vector3.hpp"
#include "core/vector4.hpp"
#include "core/matrix4x4.hpp"
#include "loaders/obj_loader.hpp"
#include "render/object_projection.hpp"
#include <iostream>

#define SCRW 1600
#define SCRH 900

using namespace sf;

int main() {

    auto cube = loadObject("cube.obj");
    // NOTE: meshes are stored in assets/models HOWEVER CMake copies them into build
    cube.scale = 0.05f;
    cube.position.z = -0.f;
    cube.constructModelMatrix();

    cube.model_matrix * Vector4(1.0, 1.0, 1.0, 0);

    auto perspective_matrix = Matrix4x4().perspective(0.1f, 10.f, 80, 16/9);
    

    RenderWindow screen(VideoMode(SCRW, SCRH), "RendED - V.0.0.1");

    while (true) {
        Event event;
        while (screen.pollEvent(event)) {
            if (event.type == Event::Closed)
                // Close app
                screen.close();
        }
        screen.clear(sf::Color::Black);

        //cube.position.z += 0.00005f;
        //cube.constructModelMatrix();

        screen.draw(objectProjection(cube, perspective_matrix));
        screen.display();
    }
}