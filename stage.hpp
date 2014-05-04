#ifndef _STAGE_H_INCLUDED
#define _STAGE_H_INCLUDED

struct stageData {
    int screenNumber;
    int screenHeight[];
    int screenLength[];
    int screenPlatformNumber[];
    int platformSize[][];
    vector playerStart;
    vector checkpointPosition[];
    int checkpointScreen;
    int enemiesPerScreen[];
};

class screen{
    int length;
    int height;
    platformEntity platforms[];
    enemyEntity enemies[];
public:
    void initScreen(int, int);
};

class stage{
    screen stageScreens[];
public:
    void initStage(stageData);
};

#endif
