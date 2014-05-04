#ifndef _LOGIC_H_INCLUDED
#define _LOGIC_H_INCLUDED

class playerMovement{

public:
    bool inControl;
    bool facing; // 1 is right, 0 is left
    bool moveLeft;
    bool faceLeft;
    bool moveRight;
    bool faceRight;
    bool Jumping;
    void playerCollision();
    void playerControl();
};

class enemyMovement{

public:
    void enemyCollision();
};

class logicClass{

public:
    void gameLogic();
};
#endif
