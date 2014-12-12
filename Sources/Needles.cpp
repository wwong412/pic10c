#include "needles.h"

Needles::Needles()
{
    fx = new QMediaPlayer;
    currentF = 0;
    frames = 3;
    inGame = false;
    QString qU("/Users/Will/Desktop/pic10c/quill.png");
      quillU = new QPixmap(qU);
    QString qD("/Users/Will/Desktop/pic10c/quillD.png");
      quillD = new QPixmap(qD);
    QString qL("/Users/Will/Desktop/pic10c/quillL.png");
      quillL = new QPixmap(qL);
    QString qR("/Users/Will/Desktop/pic10c/quillR.png");
      quillR = new QPixmap(qR);
    QString qTR("/Users/Will/Desktop/pic10c/quillTR.png");
      quillTR = new QPixmap(qTR);
    QString qLR("/Users/Will/Desktop/pic10c/quillTL.png");
    quillTL = new QPixmap(qLR);
    fx->setMedia(QUrl::fromLocalFile("/Users/Will/Desktop/pic10c/Thrown.m4a"));
    fx->setVolume(50);

}

void Needles::fire(int px, int py, QPainter *q){
    x1 = px;
    y1 = py;
    painter = q;
    inGame = true;
    fx->setPosition(0);
    fx->play();

}

void Needles::drawShots(){
    if(inGame){
        painter->drawPixmap(x1-5,y1-60-(currentF*15), 10,30,*quillU);          // top
        painter->drawPixmap(x1-5,y1+30+(currentF*15), 10,30,*quillD);          // bottom
        painter->drawPixmap(x1+20+(currentF*10),y1-40-(currentF*10), 20,20,*quillTR);  // top right
        painter->drawPixmap(x1+20+(currentF*10),y1+20+(currentF*10),20,20,*quillTL);     // bottom right

        painter->drawPixmap(x1-60-(currentF*15),y1-5,30,10,*quillL);            //left
        painter->drawPixmap(x1+30+(currentF*15),y1-5,30,10,*quillR);             //right
        painter->drawPixmap(x1-40-(currentF*10),y1-40-(currentF*10),20,20,*quillTL);   // top left
        painter->drawPixmap(x1-20-(currentF*10),y1+20+(currentF*10),20,20,*quillTR);  // bottom left

        currentF++;
        if(currentF>=frames){
            currentF = 0;
            frames = 3;
            inGame = false;
        }
    }
}
