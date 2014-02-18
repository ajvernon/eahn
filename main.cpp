#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <vectors.hpp>
#include <player.hpp>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 480), "Eahn", sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    sf::Clock clock;
    Vector world(0,0);
    Player firstPlayer;
    firstPlayer.setSprite();

    sf::Thread movementThread(&Player::characterControl, &firstPlayer);
    movementThread.launch();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(firstPlayer.sprite);
        window.display();
    }
    firstPlayer.inControl = false;
    return(0);
}
