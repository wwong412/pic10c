#include "projectiles.h"


Projectiles::Projectiles()
{
   fx_acorn = new QMediaPlayer;
   fx_acorn->setMedia(QUrl::fromLocalFile("/Users/Will/Desktop/pic10c/spear.mp3"));
   fx_acorn->setVolume(50);
   currentF = 0;
   frames = 3;
   inGame = false;
   acornSize = 25;
}

void Projectiles::fire(int px, int py, int px2, int py2, QPixmap p, QPainter *q){
    x1 = px;
    y1 = py;
    x2 = px2;
    y2 = py2;
    painter = q;
    xincr = (x1 - x2)/frames;
    yincr = (y1 - y2)/frames;
    pic = p;
    inGame = true;
    fx_acorn->setPosition(0);
    fx_acorn->play();
}

void Projectiles::drawShots2(){
    if(inGame){

        painter->drawLine(x1+15,y1+15, x1-(xincr*(currentF+1)),y1-(yincr*(currentF+1)));

        currentF+=2;
        if(currentF>=frames){
            currentF = 0;
            frames = 3;
            inGame = false;
        }
    }
}

void Projectiles::drawShots(){
    if(inGame){
        painter->drawPixmap(x1-(currentF*xincr),y1-(currentF*yincr), acornSize,acornSize,pic);
        currentF++;
        if(currentF>=frames){
            currentF = 0;
            frames = 3;
            inGame = false;
        }
    }
}
