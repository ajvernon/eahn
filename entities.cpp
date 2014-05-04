#include <iostream>
#include <cmath>
#include <vectors.hpp>
#include <entities.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace std;

// maybe I should actually write some comments, that would be good

int entity::gridCalc (int x) {
   int output;
   output = imageSize*x;
   return output;
}

void entity::initialiseEntity(int posX, int posY, int sizeOf, int initialGridX, int initialGridY, int colH, int colW) {
    position.setValues(posX,posY);
    publicPos.setVector(position);
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
        cout << "Oh deary me! " << textureFilename << " failed to load! You might want to look into that.";
        exit(EXIT_FAILURE);
    };
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(imageGridX, imageGridY, imageSize, imageSize));
    sprite.setScale(2,2);
}

void entity::updateVectors(Vector inputPos, Vector inputVel, Vector inputAcc){
    position.setVector(inputPos);
    publicPos.setVector(position);
    velocity.setVector(inputVel);
    acceleration.setVector(inputAcc);
}

void playerEntity::initPlayer(Vector initPos) {
    health = 100;
    lives = 2;
    Player.initialiseEntity(initPos.publicX,initPos.publicY,32,1,1,32,32);
    publicPos.setValues(Player.publicPos.publicX,Player.publicPos.publicY);
    Player.textureFilename = "megaman.png";
    Player.setSprite();
}

void playerEntity::updateSprite(bool faceLeft, bool faceRight, bool moveLeft, bool moveRight, bool facing){
    if ((faceLeft) && (facing)){
        if (moveLeft){
            Player.sprite.setTextureRect(sf::IntRect(Player.gridCalc(1), Player.gridCalc(2), 32, 32));
            Player.sprite.scale(sf::Vector2f(-1, 0));
            Player.sprite.move(32,0);
        }
        else {
            Player.sprite.scale(sf::Vector2f(-1, 0));
            Player.sprite.move(32,0);
            Player.sprite.setTextureRect(sf::IntRect(Player.gridCalc(1), Player.gridCalc(1), 32, 32));
        }
    }
    if ((faceLeft) && (!facing)){
        if (moveLeft){
            Player.sprite.setTextureRect(sf::IntRect(Player.gridCalc(1), Player.gridCalc(2), 32, 32));
        }
        else {
            Player.sprite.setTextureRect(sf::IntRect(Player.gridCalc(1), Player.gridCalc(1), 32, 32));
        }
    }

    if ((faceRight) && (!facing)){
        if (moveRight){
            Player.sprite.setTextureRect(sf::IntRect(Player.gridCalc(1), Player.gridCalc(2), 32, 32));
            Player.sprite.scale(sf::Vector2f(-1, 0));
            Player.sprite.move(-32,0);
        }
        else {
            Player.sprite.scale(sf::Vector2f(-1, 0));
            Player.sprite.move(-32,0);
            Player.sprite.setTextureRect(sf::IntRect(Player.gridCalc(1), Player.gridCalc(1), 32, 32));
        }
    }
    if ((faceRight) && (facing)){
        if (moveRight){
            Player.sprite.setTextureRect(sf::IntRect(Player.gridCalc(1), Player.gridCalc(2), 32, 32));
        }
        else {
            Player.sprite.setTextureRect(sf::IntRect(Player.gridCalc(1), Player.gridCalc(1), 32, 32));
        }
    }
}

void playerEntity::PublicUpdateVectors(Vector inputPos, Vector inputVel, Vector inputAcc){
    Player.updateVectors(inputPos, inputVel, inputAcc);
}

void enemyEntity::initEnemy(int HP, string texFile) {
    health = HP;
    Enemy.textureFilename = texFile;
}

void projectileEntity::initProjectile(int DMG, string texFile) {
    damage = DMG;

}


void platformEntity::initPlatform(int inputLength, int inputHeight, int inputXPos, int inputYPos, int inputType, int inputSize, string texFile) {
    length = inputLength;
    height = inputHeight;
    type = inputType;

    int gridX;
    int initGridX;
    int gridY;
    int initGridY;
    bool x;
    bool y;

    if (type == 0) {
        gridX = 1;
        initGridX = 1;
        gridY = 1;
        initGridY = 1;
    };

    int l = 0;
    int h = 0;
    while (h <= (inputHeight-1)){ // Oh dear god why did I put so many goddamn inputs on this thing
        while (l <= (inputLength-1)) {
            if (l == 0){
                gridX = initGridX;
                x = false;
            };
            if ((l < ((inputLength-1))) && (l != 0) && x == false){
                gridX = gridX +1;
                x = true;
            };
            if (l == (inputLength-1)){
                gridX = gridX +1;
            }

            if (h == 0){
                gridY = initGridY;
                x = false;
            };
            if ((h < ((inputHeight-1))) && (l != 0) && y == false){
                gridY = gridY +1;
                y = true;
            };
            if (h == (inputHeight-1)){
                gridY = gridY +1;
            }

            Platform[l][h].initialiseEntity((inputXPos + (l*inputSize)), (inputYPos + (h*inputSize)),inputSize,gridX,gridY,inputSize,inputSize);
            Platform[l][h].textureFilename = texFile;
            Platform[l][h].setSprite();
        }
        l = 0;
    }


}
