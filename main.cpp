#include <iostream>
#include <thread>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vectors.hpp>
#include <entities.hpp>
#include <stage.hpp>
#include <logic.hpp>
#include <window.hpp>

using namespace std;
void gameLogic();
//void drawWindow(sf::RenderWindow* window);
sf::Sprite * playerSprite;
sf::Sprite *platformSprite[20][20];
int main()
{

    sf::RenderWindow window(sf::VideoMode(512, 480), "Eahn", sf::Style::Close);
    window.setFramerateLimit(60);
    Vector world(0,0);
    //Player firstPlayer;

    //window.setActive(false);

    //sf::Thread graphicsThread(&drawWindow, &window);
    //graphicsThread.launch();

    //sf::Thread movementThread(&Player::characterControl, &firstPlayer);
    //sf::Thread playerDrawThread(&Player::spriteDraw, &firstPlayer);
    //movementThread.launch();
    //playerDrawThread.launch();

    //sf::Thread gameLogicThread(&gameLogic);
    //gameLogicThread.launch();
    thread t1(gameLogic)
    t1.join();

    while (window.isOpen() == true)
    {
        sf::Event event;
        while (window.pollEvent(event) == true)
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        if (playerSprite != NULL){
            window.draw(*playerSprite);
            cout << "Player sprite drawn\n";
        }

        if (playerSprite == NULL){
            cout << "Oh crap, nothing's in the memory for the player sprite!\n";
        }

        for (int l = 0; l < 20; l++){
             for (int h = 0; h < 20; h++ ){
                 if (platformSprite[l][h] != NULL){
                      window.draw(*platformSprite[l][h]);
                  }
               }
          }

        window.display();

    }
   // firstPlayer.inControl = false;
   // firstPlayer.beingDrawn = false;
    return(0);
}