#include <iostream>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vectors.hpp>

extern sf::Sprite * playerSprite;

void drawWindow(sf::RenderWindow* window){
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear(sf::Color::White);
        window->draw(*playerSprite);
        window->display();
    }
}
