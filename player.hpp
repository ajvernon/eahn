#ifndef _PLAYER_H_INCLUDED
#define _PLAYER_H_INCLUDED
#include <SFML/Graphics.hpp>

class Player
{   Vector position;
    Vector velocity;
public:
    sf::Sprite sprite;
    sf::Texture texture;
    void setSprite();
    bool isMoving = 0;
    bool facing = 0;
    int runCycle = 0;
    void movement();
    void stopMove();
    void faceLeft();
    void faceRight();
    void characterControl();
};
#endif
