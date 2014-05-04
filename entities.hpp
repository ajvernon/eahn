#ifndef _ENTITIES_H_INCLUDED
#define _ENTITIES_H_INCLUDED
#include <SFML/Graphics.hpp>
using namespace std;

class entity {
    Vector position;        // These variables store the various bits of basic data each entity has,
    Vector velocity;        // although a couple of them are useless for certain entities, it's much easier
    Vector acceleration;    // to define them once here rather than to do it a trillion times.
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
    Vector publicPos;
    void updateVectors(Vector, Vector, Vector);
};

class playerEntity {
    entity Player;
public:
    int health;
    int lives;
    void initPlayer(Vector);
    void movement();
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
    entity Platform[][20];
public:
    int length;
    int height;
    int type;
    void initPlatform(int, int, int, int, int, int, string);
};
#endif
