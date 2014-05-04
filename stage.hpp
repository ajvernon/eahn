#ifndef _STAGE_H_INCLUDED
#define _STAGE_H_INCLUDED

struct screenData {
    int height; // the height of the screen
    int length; // the length of the screen
    int numberOfEnemies; // the number of enemies the screen contains
    int enemyType[]; // the type of each enemy, stored as an integer which the enemy
                     // section of the program interprets as a certain set of data
    int numberOfPlatforms; // the number of platforms in the screen
    int platformLength[]; // these five variables set out the size and position of
    int platformHeight[]; // the platforms in the screen
    int platformXPos[];
    int platformYPos[];
    int platformSize[];
    int platformType[]; // the type of the platform, set up similarly to the enemy type
    string screenImageFile; // used only to pass file data along to the platforms
};

struct stageData {
    int screenNumber; // not sure if I need this at the moment
    screenData Screens[]; // info for all the screens contained in the stage; easily usable for a single-screen stage
                          // in a platformer like Mario rather than the Mega Man port I'm creating here
    Vector playerStart;             // Where the player starts on the first screen
    Vector checkpointPosition[];    // Where the checkpoint(s) are in the screen,
    int checkpointScreen[];         // and which screen they're on
    string stageImageFile; // the image file for the platforms and background of the stage
};

class screen{
    int length; // The data from the screenData struct is funnelled into here, which contains
    int height; // everything needed for the stage
    platformEntity platforms[];
    enemyEntity enemies[];
public:
    void initScreen(screenData);
};

class stage{
    screen stageScreens[];
public:
    void initStage(stageData);
};

#endif
