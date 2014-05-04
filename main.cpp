#include <iostream>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vectors.hpp>
#include <player.hpp>
#include <entities.hpp>
#include <stage.hpp>
#include <logic.hpp>
#include <window.hpp>
using namespace std;

void drawWindow(sf::RenderWindow* window);

int main()
{

    sf::RenderWindow window(sf::VideoMode(512, 480), "Eahn", sf::Style::Close);
    Vector world(0,0);
    Player firstPlayer;
    logicClass GameLogic;

    window.setActive(false);

    sf::Thread graphicsThread(&drawWindow, &window);
    graphicsThread.launch();

    //sf::Thread movementThread(&Player::characterControl, &firstPlayer);
    //sf::Thread playerDrawThread(&Player::spriteDraw, &firstPlayer);
    //movementThread.launch();
    //playerDrawThread.launch();

    sf::Thread gameLogicThread(&logicClass::gameLogic,&GameLogic);
    gameLogicThread.launch();

    while (window.isOpen())
    {
        /*sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(firstPlayer.sprite);
        window.display();*/
    }
    firstPlayer.inControl = false;
    firstPlayer.beingDrawn = false;
    return(0);
}
