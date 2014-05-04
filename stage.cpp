#include <iostream>
#include <string>
#include <cmath>
#include <vectors.hpp>
#include <entities.hpp>
#include <stage.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace std;

void stage::initStage(stageData Input) {
    int i = 0;
    while (i <= (Input.screenNumber -1)){
        stageScreens[i].initScreen(Input.Screens[i]);
        //stageScreens[i].platformNumber = Input.screenPlatformNumber[i];
    };

}

void screen::initScreen(screenData Input){
    length = Input.length; // This sets the size of the screen
    height = Input.height;

    int n = 0;

    while (n <= (Input.numberOfEnemies -1)){  // This initialises the enemies in the screen

    };

    n = 0;

    while (n <= (Input.numberOfPlatforms -1)){  // This initialises the platforms in the screen
        platforms[n].initPlatform(Input.platformLength[n], Input.platformHeight[n],
                                  Input.platformXPos[n], Input.platformYPos[n], Input.platformType[n],
                                  Input.platformSize[n], Input.screenImageFile);
    };
}
