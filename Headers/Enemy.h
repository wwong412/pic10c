#ifndef ENEMY_H
#define ENEMY_H

#include <QRect>
#include "constants.h"

namespace ATTRIBUTES{

// SPEED
const int MAN_SPD = 5;
const int H_MAN_SPD = 4;
const int DOZER_SPD = 2;
const int JACK_MAN_SPD = 10;

// DIRECTION
const int UP = 0;
const int DOWN = 1;
const int RIGHT = 2;
const int LEFT = 3;

// SLOW SPEED
const int DURATION = 20;
const int SLOW_SPD = 1;

// ENEMY SIZES
const int SMALL_X = 25;
const int SMALL_Y = 40;
const int BIG_X = 40;
const int BIG_Y = 40;

// HITBOX MARGINS
const int SML_MAR = 5;
const int BIG_MAR = 15;

}

// Enemy class
// Move and spawn functions are called in gamewindow classes

class Enemy
{
public:
    Enemy();
    // spawns enemy with initilzing values if it is not in game and not dead
    void spawn(int array [][CONSTANTS::B_COLS], int length, int wID);     
    // move the enemy coordinates
    void move(int array [][CONSTANTS::B_COLS] , int array2[][CONSTANTS::B_COLS], int &lives);      // will move the enemies
    // subtracts amount of damgage from enemy
    void damaged(int dmg);
    // checks to see if hp is less than 0
    bool checkDeath();
    // changes enemy's speed to slow
    void slowed();
    // remove enemy from game
    void eraseEnemy();
    // set values depending on enemy type
    void setHardHat();
    void setDozer();
    void setJack();

    QRect *rect;            // for hit dectection
    bool inGame;            // bool for enemy in game

    int x;              // x,y coords
    int y;
    int hp;             // health
    int framewalk;      // used to keep track of walking frame
    bool isSlowed;
    int stopTime;
    bool dead;
    int type;        // enemy type

private:
    int xTile;              // tiles to keep track of num of tiles moved
    int yTile;   
    int direction;
    int walkLength;                                 // length of walking in one tile
    bool prevUp, prevDown, prevRight, prevLeft;     // used to determine walking path
    int speed;                                         // walk speed

};

#endif // ENEMY_H
