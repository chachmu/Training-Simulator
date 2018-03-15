#include "PhysicsObject.hpp"

PhysicsObject::PhysicsObject(vec2d position) {
    this->position = position;
    rect = sf::RectangleShape(sf::Vector2f(40,40));
    rect.setOrigin(20,20);
    rect.setFillColor(sf::Color::Blue);
    rect.setPosition(position.x, position.y);
    held = false;
}

void PhysicsObject::draw(sf::RenderWindow &window) {
    if (!held) {
        window.draw(rect);
    }
}