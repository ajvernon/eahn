#include <iostream>
#include <string>
#include <cmath>
#include <vectors.hpp>
#include <entities.hpp>
#include <stage.hpp>
#include <SFML/Graphics.hpp>
using namespace std;

void stage::initStage(stageData Input) {
    int i;
    while (i <= (Input.screenNumber -1)){
        stageScreens[i].initScreen(Input.screenLength[i], Input.screenHeight[i]);
        stageScreens[i].platformNumber = Input.screenPlatformNumber[i];
    }
}

void screen::initScreen(int screenLength, int screenHeight){
    length = screenLength;
    height = screenHeight;
}