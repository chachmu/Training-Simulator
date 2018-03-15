#ifndef __Robot__
#define __Robot__

#include <SFML/Graphics.hpp>
#include "Sensor.hpp"
#include "PhysicsObject.hpp"

class Robot {
public:
    sf::RectangleShape rect;
    sf::RectangleShape grabber;

    vec2d position;
    vec2d velocity;
    float angle;

    Sensor sensor1;
    Sensor sensor2;

    bool holding;
    PhysicsObject* held;

    Robot(vec2d position);

    void grabActivated(std::vector <PhysicsObject*> &objects);
    void update(std::vector <bool> keys, std::vector <PhysicsObject*> &objects, std::vector <Line*> &lines);
    void draw(sf::RenderWindow &window);
};


#endif __Robot__
