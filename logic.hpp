#ifndef _LOGIC_H_INCLUDED
#define _LOGIC_H_INCLUDED

class playerMovement{

public:
    bool inControl;
    void playerCollision();
    void playerControl();
};

class enemyMovement{

public:
    void enemyCollision();
};

#endif
