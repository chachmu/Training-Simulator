#include <iostream>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Vector.hpp"
#include "PhysicsObject.cpp"
#include "Robot.cpp"
#include "Sensor.cpp"
#include "Line.cpp"

int main()
{

    //TODO: Figure out how to turn on antialiasing
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Training Simulator");
    window.setFramerateLimit(60);

    std::vector <bool> keys(5);

    std::vector <PhysicsObject*> objects;
    PhysicsObject phys(vec2d(100,100));
    objects.push_back(&phys);
    PhysicsObject phys2(vec2d(100,400));
    objects.push_back(&phys2);

    std::vector <Line*> lines;
    Line ln(vec2d(300,200), vec2d(400,200));
    lines.push_back(&ln);
    Line ln2(vec2d(500,100), vec2d(400,400));
    lines.push_back(&ln2);

    Robot robot(vec2d(200,200));

    while (window.isOpen())
    {
        keys[4] = false;
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyReleased:
                    if (event.key.code == sf::Keyboard::Space) {
                        keys[4] = true;
                    }
                    break;
            }
        }

        //Get Keyboard input
        //Swap this out for network control in the final version
        keys[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        keys[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        keys[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        keys[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S);

        robot.update(keys, objects, lines);

        window.clear(sf::Color::White);

        for (PhysicsObject* object : objects) {
            object->draw(window);
        }
        for (Line* line : lines) {
            line->draw(window);
        }

        robot.draw(window);

        window.display();
    }

    return 0;
}