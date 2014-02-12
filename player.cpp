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
}

void Player::movement(){
    if (facing)
        sprite.move(-1,0);
    else
        sprite.move(1,0);

    if (runCycle == 0)
    {
        sprite.setTextureRect(sf::IntRect(190, 11, 24, 22));
        runCycle = runCycle + 1;
    };

    if (runCycle == 1)
    {
        sprite.setTextureRect(sf::IntRect(217, 10, 17, 24));
        runCycle = runCycle + 1;
    };

    if (runCycle == 2)
    {
        sprite.setTextureRect(sf::IntRect(238, 12, 21, 22));
        runCycle = runCycle + 1;
    };
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

void Player::characterControl(){
    bool inControl = 1;

    while (inControl){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            faceLeft();
            sprite.move(-1,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            faceRight();
            sprite.move(1,0);
        }
    }

}
