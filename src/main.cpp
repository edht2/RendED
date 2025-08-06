#include "core/vector3.hpp"
#include "core/vector4.hpp"
#include "core/matrix4x4.hpp"
#include "loaders/obj_loader.hpp"
#include "render/object_projection.hpp"
#include <iostream>

#define SCRW 1600
#define SCRH 900

//using namespace sf;

int main() {

    sf::Clock clock;

    float ticks = 0;

    auto cube = *loadObject("monkey.obj");
    
    cube.scale = 0.05f;
    cube.constructModelMatrix();

    auto perspective_matrix = Matrix4x4().perspective(0.1f, 10.f, 80, 16/9);
    
    sf::RenderWindow window(sf::VideoMode(SCRW, SCRH), "RendED - SFML");

    while (window.isOpen()) {
        std::cout << 1 / (clock.restart().asSeconds()) << " FPS" << std::endl;

        ticks += 0.0005f;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                // Close app
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::W) {cube.position.z += 0.05f;}
                if (event.key.code == sf::Keyboard::A) {cube.position.x += 0.05f;}
                if (event.key.code == sf::Keyboard::S) {cube.position.z -= 0.05f;}
                if (event.key.code == sf::Keyboard::D) {cube.position.x -= 0.05f;}
                if (event.key.code == sf::Keyboard::Q) {cube.position.y -= 0.05f;}
                if (event.key.code == sf::Keyboard::E) {cube.position.y += 0.05f;}
                cube.constructModelMatrix();
                // after any changes to the models transform, you must reconstruct the model matrix
            }
        }

        window.clear();

        window.draw(objectProjection(&cube, perspective_matrix, ticks));

        window.display();
        
    }
}