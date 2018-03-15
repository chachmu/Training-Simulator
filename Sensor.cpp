#include "Sensor.hpp"


Sensor::Sensor() { //I have to have this?
    position = vec2d(0,0);
}

Sensor::Sensor(vec2d position, int direction) {
    this->position = position;
    this->direction = direction;

    rect = sf::RectangleShape(sf::Vector2f(10,10));
    if (direction < 0) {
        rect.setOrigin(20, 35); //FIX THIS
    }
    else {
        rect.setOrigin(-10, 35);
    }
    rect.setFillColor(sf::Color::Blue);
    rect.setPosition(position.x, position.y);
    lineDetected = false;
}

void Sensor::update(vec2d position, float angle, std::vector <Line*> &lines) {
    this->position = position;
    rect.setPosition(position.x, position.y);
    rect.setRotation(angle);

    sf::Rect <float> sns = rect.getGlobalBounds();
    lineDetected = false;
    for (Line* line : lines) {
        sf::Rect <float> rct = line->rect.getGlobalBounds();
        if (sns.intersects(rct)) {
            lineDetected = true;
            break;
        }
    }


    if (lineDetected) {
        rect.setFillColor(sf::Color::Red);
    }
    else {
        rect.setFillColor(sf::Color::Blue);
    }
}

void Sensor::draw(sf::RenderWindow &window) {
    window.draw(rect);
}