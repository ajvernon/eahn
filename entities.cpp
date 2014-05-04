#include <iostream>
#include <cmath>
#include <vectors.hpp>
#include <entities.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

// maybe I should actually write some comments, that would be good

int entity::gridCalc (int x) {
   int output;
   output = imageSize*x;
   return output;
}

void entity::initialiseEntity(int posX, int posY, int sizeOf, int initialGridX, int initialGridY, int colH, int colW) {
    position.setValues(posX,posY);
    velocity.setValues(0,0);
    acceleration.setValues(0,0);
    imageSize = sizeOf;
    imageGridX = gridCalc(initialGridX);
    imageGridY = gridCalc(initialGridY);
    collisionHeight = colH;
    collisionWidth = colW;
}

void entity::setSprite() {
    if (!texture.loadFromFile(textureFilename))
    {
        cout << "Oh shit! " << textureFilename << " failed to load! You might want to look into that.";
        exit(EXIT_FAILURE);
    };
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(imageGridX, imageGridY, imageSize, imageSize));
    sprite.setScale(2,2);
}

void playerEntity::initPlayer() {
    health = 100;
    lives = 2;
    Player.initialiseEntity(0,0,32,1,1,32,32);
    Player.textureFilename = "megaman.png";
    Player.setSprite();
}

void enemyEntity::initEnemy(int HP, string texFile) {
    health = HP;
    Enemy.textureFilename = texFile;
}

void projectileEntity::initProjectile(int DMG, string texFile) {
    damage = DMG;

}


void platformEntity::initPlatform() {

}
