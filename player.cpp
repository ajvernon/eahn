#include <iostream>
#include <cmath>
#include <vectors.hpp>
#include <player.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

void Player::setSprite(){
    if (!texture.loadFromFile("megaman.png"))
    {
        cout << "Oh shit! megaman.png failed to load! You might want to look into that.";
        exit(EXIT_FAILURE);
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
        sf::sleep(sf::milliseconds(120));
    };

    if (runCycle == 1)
    {
        sprite.setTextureRect(sf::IntRect(217, 10, 17, 24));
        runCycle = runCycle + 1;
        sf::sleep(sf::milliseconds(120));
    };

    if (runCycle == 2)
    {
        sprite.setTextureRect(sf::IntRect(238, 10, 21, 24));
        runCycle = runCycle + 1;
        sf::sleep(sf::milliseconds(120));
    };

    if (runCycle == 3)
    {
        sprite.setTextureRect(sf::IntRect(217, 10, 17, 24));
        runCycle = 0;
        sf::sleep(sf::milliseconds(120));
    };
}

void Player::movement(long double xMove,long double yMove, long double xCap,long double yCap){
    if ((xMove == 0) && (yMove == 0)){
        velocity.setValues(0,0);
        acceleration.setValues(0,0);
    }
    if (acceleration.publicX != xMove){
        acceleration.setValues(xMove,acceleration.publicY);
    }
    if (acceleration.publicY != yMove){
        acceleration.setValues(acceleration.publicX,yMove);
    }

    if (xCap >= 0){
        if ((velocity.publicX + acceleration.publicX) >= xCap){
            velocity.setValues(xCap,velocity.publicY);
        }
        if ((velocity.publicX + acceleration.publicX) <= xCap) {
            velocity.addValues(acceleration.publicX,velocity.publicY);
        }
    }
    if (xCap < 0){
        if ((velocity.publicX + acceleration.publicX) <= xCap){
            velocity.setValues(xCap,velocity.publicY);
        }
        if ((velocity.publicX + acceleration.publicX) >= xCap) {
            velocity.addValues(acceleration.publicX,velocity.publicY);
        }
    }


    /*if (velocity.publicX == 0) {
        velocity.addValues(xMove, 0);
    }
    if (velocity.publicY == 0) {
        velocity.addValues(0, yMove);
    }*/
    position.addValues(velocity.publicX, velocity.publicY);
    //velocity.addValues(0, -1);

}

void Player::spriteDraw (){
    if (!isSpriteSet){
        setSprite();
        beingDrawn = 1;
    }

    while (beingDrawn){
    if ((velocity.publicX == 0) && (velocity.publicY == 0)){
        sprite.setTextureRect(sf::IntRect(103, 10, 21, 24));
    };
    if (velocity.publicX > 0)
    {
            if (facing){
            sprite.setTextureRect(sf::IntRect(103, 10, 21, 24));
            faceRight();
        }
        rCycle();
    };
    if (velocity.publicX < 0)
    {
        if (!facing){
            sprite.setTextureRect(sf::IntRect(103, 10, 21, 24));
            faceLeft();
        };

        rCycle();
    }
    sprite.move(velocity.publicX,velocity.publicY);
    }
}

void Player::characterControl(){
    inControl = 1;

    //sf::Mutex mutex;


    while (inControl){
        //mutex.lock();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            if (!facing){
                movement(0,0,0,0);
            }
            movement(-1, 0, -20, 0);
            //sf::sleep(sf::milliseconds(10));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            if (facing){
                movement(0,0,0,0);
            }
            movement(1, 0, 20, 0);
            //sf::sleep(sf::milliseconds(10));
        }
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            movement(0,0,0,0);

        }
        //view.setCenter(position.publicX, position.publicY);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            inControl = 0;
        }
        //mutex.unlock();
        //spriteDraw();
    }
}
