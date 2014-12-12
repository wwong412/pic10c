#ifndef DRAW_H
#define DRAW_H

#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QPoint>

#include "tile.h"
#include "pictures.h"
#include "enemy.h"
#include "wave.h"
#include "needles.h"
#include "projectiles.h"
#include "constants.h"

// This is the Drawing class that contains most of the paint functions in the game.
// They are called from the gamewindow class with the appropriate inputs


class Draw
{
public:
    Draw();
     // sets Qpainter
     void setPainter(QPainter* paint);
     // draws the background board
     void drawBoard(int gameBoard[][12], bool waveStarted, bool loaded);
     // draws users lives, money, pause, and fast forward buttons
     void drawTop(bool loaded, int money, int lives, int wave_num, int speed);
     // draws towers that are placed.
     void drawTowers(bool loaded, Tile gameBoard[][CONSTANTS::B_COLS]);
     // draws the enemies in the game
     void drawMen(Wave waves[], int wave_num);
     // draws the enemies health over them
     void drawHealth(Wave waves[],int wave_num);
     // draws tower upgrade menu when clicked on
     void drawUpgrade(Tile gameBoard[][CONSTANTS::B_COLS], bool towerClicked);
     // draws tower selection if user can build there
     void drawPick(bool towerPick, Tile gameBoard[][12]);
     // draws webs on slowed enemies
     void drawWebs(Wave waves[], int wave_num);
     // draws the towers shooting mechanics
     void drawAcorns(Tile gameBoard[][CONSTANTS::B_COLS]);
     // draws pause/ quit menu
     void drawMenu(bool started);

    QPainter* painter;
    Pictures p;
};

#endif // DRAW_H
