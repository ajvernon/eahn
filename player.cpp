#include <iostream>
#include <cmath>
#include <vectors.hpp>
#include <player.hpp>
#include <SFML/Graphics.hpp>

void Player::setSprite(){
    if (!texture.loadFromFile("megaman.png"))
    {
        // error of some sort
    };
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(103, 10, 21, 24));
    sprite.setScale(2,2);
    position.setValues(256,240);
    sprite.setPosition(position.publicX,position.publicY);
    view.setCenter(position.publicX,position.publicY);
    view.setSize(512,480);
    isMoving = 0;
    facing = 0;
    runCycle = 0;
}

void Player::stopMove (){
    sprite.setTextureRect(sf::IntRect(103, 10, 21, 24));
}

void Player::faceLeft(){
    facing = 1;
    sprite.scale(-1,1);
    sprite.move(38,0);
}

void Player::faceRight(){
    facing = 0;
    sprite.scale(-1,1);
    sprite.move(-38,0);
}

void Player::rCycle() {
    if (runCycle == 0)
    {
        sprite.setTextureRect(sf::IntRect(190, 10, 24, 23));
        runCycle = runCycle + 1;
        sf::sleep(sf::milliseconds(60));
    };

    if (runCycle == 1)
    {
        sprite.setTextureRect(sf::IntRect(217, 10, 17, 24));
        runCycle = runCycle + 1;
        sf::sleep(sf::milliseconds(60));
    };

    if (runCycle == 2)
    {
        sprite.setTextureRect(sf::IntRect(238, 10, 21, 24));
        runCycle = runCycle + 1;
        sf::sleep(sf::milliseconds(60));
    };

    if (runCycle == 3)
    {
        sprite.setTextureRect(sf::IntRect(217, 10, 17, 24));
        runCycle = 0;
        sf::sleep(sf::milliseconds(60));
    };
}


void Player::characterControl(){
    inControl = 1;

    while (inControl){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            if (!facing){
                stopMove();
                faceLeft();
            }
            sprite.move(-20,0);
            position.addValues(-20, 0);
            sf::sleep(sf::milliseconds(10));
            rCycle();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            if (facing){
                stopMove();
                faceRight();
            }
            sprite.move(20,0);
            position.addValues(20, 0);
            sf::sleep(sf::milliseconds(100));
            rCycle();
        }
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            stopMove();
        }
        view.setCenter(position.publicX, position.publicY);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            inControl = 0;
        }
    }
}
