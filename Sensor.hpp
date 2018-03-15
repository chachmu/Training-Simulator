#ifndef __Sensor__
#define __Sensor__

#include <SFML/Graphics.hpp>
#include "Vector.hpp"
#include "Line.hpp"

class Sensor {
public:
    sf::RectangleShape rect;
    vec2d position;
    int direction;
    bool lineDetected;

    Sensor(vec2d position, int direction);
    Sensor();

    void update(vec2d position, float angle, std::vector <Line*> &lines);
    void draw(sf::RenderWindow &window);
};


#endif __Sensor__
