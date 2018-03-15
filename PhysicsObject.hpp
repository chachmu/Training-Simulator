#ifndef __PhysicsObject__
#define __PhysicsObject__

#include <SFML/Graphics.hpp>
#include "Vector.hpp"


class PhysicsObject {
public:
    sf::RectangleShape rect;

    vec2d position;
    vec2d velocity;
    bool held;

    PhysicsObject(vec2d position);

    void update();

    void draw(sf::RenderWindow &window);
};


#endif __PhysicsObject__
