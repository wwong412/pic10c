#ifndef NEEDLES_H
#define NEEDLES_H

#include <QPainter>
#include <QDebug>
#include <QTransform>
#include <QMediaPlayer>

#include "constants.h"


// class that is used to draw the porcupines needles
class Needles
{
public:
    Needles();
    void fire(int px, int py, QPainter *q);
    void drawShots();
    bool inGame;

private:
    QPainter *painter;

    QPixmap* quillU;
    QPixmap* quillD;
    QPixmap* quillL;
    QPixmap* quillR;
    QPixmap* quillTR;
    QPixmap* quillTL;

    QMediaPlayer* fx;


    int currentF;
    int frames;
    int x1;
    int y1;
};

#endif // NEEDLES_H
