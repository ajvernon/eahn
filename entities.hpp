#ifndef _ENTITIES_H_INCLUDED
#define _ENTITIES_H_INCLUDED
#include <SFML/Graphics.hpp>
using namespace std;

class entity {
    Vector position;
    Vector velocity;
    Vector acceleration;
    int collisionHeight;
    int collisionWidth;
    int imageSize;
    int imageGridX;
    int imageGridY;
public:
    sf::Sprite sprite;
    sf::Texture texture;
    string textureFilename;
    void initialiseEntity(int, int, int, int, int, int, int);
    void setSprite();
    int gridCalc(int);
};

class playerEntity {
    entity Player;
public:
    int health;
    int lives;
    void initPlayer();
};

class enemyEntity {
    entity Enemy;
public:
    int health;
    void initEnemy(int, string);
};

class projectileEntity {
    entity Projectile;
public:
    int damage;
    void initProjectile(int, string);
};

class platformEntity {
    entity Platform;
public:
    int length;
    int height;
    void initPlatform();
};
#endif
