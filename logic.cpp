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

extern sf::Sprite * playerSprite;
class playerEntity;
class stage;
extern sf::Sprite *platformSprite[20][20];


int passPointer(){

}

void playerMovement::playerCollision(){

}

void playerMovement::playerControl(){
    //while (inControl == true){
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
    //}
    //if
}

void gameLogic (){
    playerMovement firstActualPlayer;
    stageData testStageData;
    playerEntity ThePlayer;
    stage testStage;
    Vector playerPos, playerVel, playerAcc;

    firstActualPlayer.facing = true;
    firstActualPlayer.inControl = true;
    sf::Mutex mutex;
    mutex.lock();
    const char t[] = "test.png";
                                            // THIS ISN'T EVEN MY DATA'S FINAL FORM
    testStageData.screenNumber = 1;
    testStageData.playerStartX = 10;
    testStageData.playerStartY = 100;
    testStageData.checkpointScreen[0] = 1;
    testStageData.checkpointPosition[0].setValues(10,100);
    for (int i=0; i<9; i++){
        testStageData.stageImageFile[i] = t[i];
    }

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

    for (int i=0; i<9; i++){
        testStageData.Screens[0].screenImageFile[i] = testStageData.stageImageFile[i];
    }


    testStage.initStage(testStageData);

    ThePlayer.initPlayer();


    playerPos.setValues(10, 100);
    ThePlayer.Player.updatePosition(playerPos);
    playerVel.setValues(0,0);
    playerAcc.setValues(0,0);
    int maxVelX;
    int maxVelY;

//    playerSprite = &ThePlayer.Player.sprite;

    mutex.unlock();

    //sf::Thread playerMovementThread (&playerMovement::playerControl, &firstActualPlayer);
    //playerMovementThread.launch();

    bool gameRunning = true;
    sf::Clock clock;
    sf::Time elapsed;
    while (gameRunning == true){
        firstActualPlayer.playerControl();
        elapsed = clock.getElapsedTime();
        cout << elapsed.asSeconds() << "\n";
    if (elapsed.asSeconds()>=(1/24)){
        mutex.lock();
        if (firstActualPlayer.moveLeft)
        {
            if ((firstActualPlayer.Jumping) && ((playerAcc.publicY >= -0.1) || (playerAcc.publicY <= 0.1))){
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
            if ((firstActualPlayer.Jumping) && ((playerAcc.publicY >= -0.1) || (playerAcc.publicY <= 0.1)) == 0){
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

        if (((playerVel.publicY >= -0.1) || (playerVel.publicY <= 0.1)) && ((playerAcc.publicY >= -0.1) || (playerAcc.publicY <= 0.1))) {firstActualPlayer.Jumping = false;}

        if (firstActualPlayer.faceLeft){
            if (playerVel.publicX <= maxVelX){
                playerVel.setValues(maxVelX,playerVel.publicY);
                playerAcc.setValues(0,playerAcc.publicY);
            }
            if (playerVel.publicY <= maxVelY){
                playerVel.setValues(playerVel.publicX,maxVelY);
                playerAcc.setValues(playerAcc.publicX,0);
            }
            playerVel.addValues((playerAcc.publicX),(playerAcc.publicY));
            playerPos.addValues(playerVel.publicX, playerVel.publicY);
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
            playerVel.addValues((playerAcc.publicX),(playerAcc.publicY));
            playerPos.addValues(playerVel.publicX, playerVel.publicY);
        }
        ThePlayer.Player.updatePosition(playerPos);
        //ThePlayer.updateSprite(firstActualPlayer.faceLeft,firstActualPlayer.faceRight,firstActualPlayer.moveLeft,firstActualPlayer.moveRight,firstActualPlayer.facing);
        clock.restart();
        mutex.unlock();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            gameRunning = false;
        }
        }
    }
}