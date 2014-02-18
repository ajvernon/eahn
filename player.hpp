#ifndef _PLAYER_H_INCLUDED
#define _PLAYER_H_INCLUDED
#include <SFML/Graphics.hpp>

class Player
{   Vector position;
    Vector velocity;
public:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::View view;
    void setSprite();
    bool isMoving;
    bool facing;
    int runCycle;
    bool inControl;
    void stopMove();
    void faceLeft();
    void faceRight();
    void characterControl();
    void rCycle();
};
#endif
