#ifndef __Line__
#define __Line__

#include <SFML/Graphics.hpp>
#include "Vector.hpp"


class Line {
public:
    //This can be upgraded to support other shapes of lines (probably)
    sf::RectangleShape rect;

    vec2d start;
    vec2d end;

    Line(vec2d start, vec2d end);

    void draw(sf::RenderWindow &window);
};


#endif __Line__
