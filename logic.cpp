#include <iostream>
#include <string>
#include <cmath>
#include <vectors.hpp>
#include <entities.hpp>
#include <stage.hpp>
#include <logic.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace std;

sf::Sprite * playerSprite;

int passPointer(){

}

void playerMovement::playerCollision(){

}

void playerMovement::playerControl(){
    while (inControl == true){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            moveLeft = true;
            moveRight = false;
            faceLeft = true;
            faceRight = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            moveRight = true;
            moveLeft = false;
            faceRight = true;
            faceLeft = false;
        }
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            moveLeft = false;
            moveRight = false;
        }
    }
    //if
}

void logicClass::gameLogic (){
    playerMovement firstActualPlayer;
    firstActualPlayer.facing = true;

    playerEntity ThePlayer;

    firstActualPlayer.inControl = true;
    sf::Thread playerMovementThread (&playerMovement::playerControl, &firstActualPlayer);
    playerMovementThread.launch();



    stageData testStageData;                            // THIS ISN'T EVEN MY DATA'S FINAL FORM
    testStageData.screenNumber = 1;
    testStageData.playerStart.setValues(10,100);
    testStageData.checkpointScreen[0] = 1;
    testStageData.checkpointPosition[0].setValues(10,100);
    testStageData.stageImageFile = "test.png";

    testStageData.Screens[0].height = 480;
    testStageData.Screens[0].length = 512;
    testStageData.Screens[0].numberOfEnemies = 2;
    testStageData.Screens[0].numberOfPlatforms = 2;
    testStageData.Screens[0].platformHeight[0] = 1;
    testStageData.Screens[0].platformLength[0] = 20;
    testStageData.Screens[0].platformSize[0] = 16;
    testStageData.Screens[0].platformXPos[0] = 0;
    testStageData.Screens[0].platformYPos[0] = 250;
    testStageData.Screens[0].platformType[0] = 0;

    testStageData.Screens[0].platformHeight[1] = 1;
    testStageData.Screens[0].platformLength[1] = 3;
    testStageData.Screens[0].platformSize[1] = 16;
    testStageData.Screens[0].platformXPos[1] = 150;
    testStageData.Screens[0].platformYPos[1] = 50;
    testStageData.Screens[0].platformType[1] = 0;

    testStageData.Screens[0].screenImageFile = testStageData.stageImageFile;

    stage testStage;
    testStage.initStage(testStageData);

    ThePlayer.initPlayer(testStageData.playerStart);

    Vector playerPos, playerVel, playerAcc;
    playerPos.setValues(ThePlayer.publicPos.publicX, ThePlayer.publicPos.publicY);
    playerVel.setValues(0,0);
    playerAcc.setValues(0,0);
    int maxVelX;
    int maxVelY;

    playerSprite = &ThePlayer.Player.sprite;

    bool gameRunning = true;
    sf::Clock clock;
    sf::Time elapsed;
    while (gameRunning == true){
        elapsed = clock.getElapsedTime();
        cout << elapsed.asSeconds() << "\n";
    if (elapsed.asSeconds()>=(1/24)){
        if (firstActualPlayer.moveLeft)
        {
            if ((firstActualPlayer.Jumping) && playerAcc.publicY == 0){
                playerAcc.setValues(-10,-10);
                playerVel.addValues(0,50);
                maxVelX = -30;
                maxVelY = -50;
            }
            else {
                playerAcc.setValues(-10, playerAcc.publicY);
                maxVelX = -30;
            }
        }
        if (firstActualPlayer.moveRight)
        {
            if ((firstActualPlayer.Jumping) && playerAcc.publicY == 0){
                playerAcc.setValues(10,-10);
                playerVel.addValues(0,50);
                maxVelX = 30;
                maxVelY = -50;
            }
            else {
                playerAcc.setValues(10, playerAcc.publicY);
                maxVelX = 30;
            }
        }

        if ((playerVel.publicY == 0) && (playerAcc.publicY == 0)) {firstActualPlayer.Jumping = false;}

        if (firstActualPlayer.faceLeft){
            if (playerVel.publicX <= maxVelX){
                playerVel.setValues(maxVelX,playerVel.publicY);
                playerAcc.setValues(0,playerAcc.publicY);
            }
            if (playerVel.publicY <= maxVelY){
                playerVel.setValues(playerVel.publicX,maxVelY);
                playerAcc.setValues(playerAcc.publicX,0);
            }
            playerVel.addValues((playerAcc.publicX/24),(playerAcc.publicY/24));
        }

        if (firstActualPlayer.faceLeft){
            if (playerVel.publicX >= maxVelX){
                playerVel.setValues(maxVelX,playerVel.publicY);
                playerAcc.setValues(0,playerAcc.publicY);
            }
            if (playerVel.publicY >= maxVelY){
                playerVel.setValues(playerVel.publicX,maxVelY);
                playerAcc.setValues(playerAcc.publicX,0);
            }
            playerVel.addValues((playerAcc.publicX/24),(playerAcc.publicY/24));
        }
        ThePlayer.PublicUpdateVectors(playerPos,playerVel,playerAcc);
        ThePlayer.updateSprite(firstActualPlayer.faceLeft,firstActualPlayer.faceRight,firstActualPlayer.moveLeft,firstActualPlayer.moveRight,firstActualPlayer.facing);
        clock.restart();
        }
    }
}
