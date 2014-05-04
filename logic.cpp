#include <iostream>
#include <string>
#include <cmath>
#include <vectors.hpp>
#include <entities.hpp>
#include <stage.hpp>
#include <logic.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

void playerMovement::playerCollision(){
    while (inControl == true){

    }
}

void playerMovement::playerControl(){
    //if
}

void gameLogic (){
    playerMovement.inControl = true;
    sf::Thread playerMovementThread (*playerMovement::playerControl, &firstActualPlayer);
    playerMovementThread.launch();

    while (gameRunning == true){

    }
}
