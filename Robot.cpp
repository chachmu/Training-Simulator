#include "Robot.hpp"

Robot::Robot(vec2d position) {
    this->position = position;

    rect = sf::RectangleShape(sf::Vector2f(50,80));
    grabber = sf::RectangleShape(sf::Vector2f(50,30));

    rect.setOrigin(25,40); //Sets rotation around center, could be moved to match wheel positions
    grabber.setOrigin(25,70);

    rect.setFillColor(sf::Color::Green);
    grabber.setFillColor(sf::Color::Transparent);
    grabber.setOutlineColor(sf::Color::Black);
    grabber.setOutlineThickness(-3);

    rect.setPosition(position.x, position.y);
    grabber.setPosition(position.x, position.y);

    velocity = vec2d(0,0);
    angle = 0;

    holding = false;

    sensor1 = Sensor(position, -1);
    sensor2 = Sensor(position, 1);
}

void Robot::update(std::vector <bool> keys, std::vector <PhysicsObject*> &objects, std::vector <Line*> &lines) {
    velocity = vec2d(0,0);
    if (keys[2]) {
        velocity = velocity - vec2d(0,2).rotDeg(angle);
    }
    if (keys[3]) {
        velocity = velocity + vec2d(0,2).rotDeg(angle);
    }

    if (keys[0]) {
        angle -= 3;
    }
    if (keys[1]) {
        angle += 3;
    }

    if(keys[4]) {
        grabActivated(objects);
    }

    position = position + velocity;
    rect.setPosition(position.x, position.y);
    grabber.setPosition(position.x,position.y);
    rect.setRotation(angle);
    grabber.setRotation(angle);

    sensor1.update(position, angle, lines);
    sensor2.update(position, angle, lines);
}


void Robot::grabActivated(std::vector <PhysicsObject*> &objects) {
    if (!holding) {
        sf::Rect <float> rbt = grabber.getGlobalBounds();

        for (PhysicsObject* object : objects) {
            sf::Rect <float> rct = object->rect.getGlobalBounds();
            if (rbt.intersects(rct)) {
                holding = true;
                held = object;
                object->held = true;
                grabber.setFillColor(object->rect.getFillColor());
                break;
            }
        }
    }
    else {
        holding = false;
        grabber.setFillColor(sf::Color::Transparent);
        held->held = false;
        vec2d heldPosition = position - vec2d(0, 55).rotDeg(angle);
        held->rect.setPosition(heldPosition.x, heldPosition.y);
        held->rect.setRotation(angle);
        held = NULL;
    }
}

void Robot::draw(sf::RenderWindow &window) {
    window.draw(rect);
    window.draw(grabber);

    sensor1.draw(window);
    sensor2.draw(window);
}