#include "Line.hpp"

Line::Line(vec2d start, vec2d end) {
    this->start = start;
    this->end = end;
    vec2d ln = start - end;

    rect = sf::RectangleShape(sf::Vector2f(5, ln.mag()));
    rect.setOrigin(2.5, 0);
    rect.setPosition(start.x, start.y);
    rect.setRotation(ln.angle() - 90);

    rect.setFillColor(sf::Color::Black);

}

void Line::draw(sf::RenderWindow &window) {
        window.draw(rect);
}