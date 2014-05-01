#ifndef _PLAYER_H_INCLUDED
#define _PLAYER_H_INCLUDED
#include <SFML/Graphics.hpp>

class Player
{   Vector position;
    Vector velocity;
    Vector acceleration;
public:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::View view;
    void setSprite();
    bool isSpriteSet;
    bool beingDrawn;
    bool isMoving;
    bool facing;
    bool inAir;
    int runCycle;
    bool inControl;
    void faceLeft();
    void faceRight();
    void movement(long double, long double, long double, long double);
    void characterControl();
    void rCycle();
    void spriteDraw();
};
#endif
