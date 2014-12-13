#ifndef PROJECTILES_H
#define PROJECTILES_H
#include <QDebug>
#include <QPainter>
#include <QPixmap>
#include <QPen>
#include <QMediaPlayer>

#include "constants.h"

// class used to draw acorns and frog's attack
class Projectiles
{
public:
    Projectiles();
    void fire(int px, int py, int px2, int py2, QPixmap p,QPainter *q);
    void drawShots();
    void drawShots2();
    bool inGame;

private:

    QPainter *painter;
    QPixmap pic;

    int currentF;
    int frames;

    int acornSize;

   int x1;
   int x2;
   int y1;
   int y2;
   int xincr;
   int yincr;

   QMediaPlayer* fx_acorn;

};

#endif // PROJECTILES_H
