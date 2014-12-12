#include "draw.h"
Draw::Draw()
{
}

// gives it painter from gamewindow
void Draw::setPainter(QPainter* paint){
    painter = paint;
}

// draws the gameboard tiles from given 2d array of ints
void Draw::drawBoard(int gameBoard[][CONSTANTS::B_COLS], bool waveStarted,bool loaded){
if(loaded){

    for(size_t i = 0, n = CONSTANTS::B_ROWS; i < n ; i++ ){
        for(size_t j = 0, n = CONSTANTS::B_COLS; j < n; j++){
            if(gameBoard[i][j]==CONSTANTS::REG_TREE){
                 painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.tree1);
            }
            else  if(gameBoard[i][j]==CONSTANTS::ACROSS){
                 painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.across);
            }
            else if(gameBoard[i][j]==CONSTANTS::VERTICAL){
                 painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.vertical);
            }
            else if(gameBoard[i][j]==CONSTANTS::RIGHT_DOWN){
                 painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.rd3);
            }
            else if(gameBoard[i][j]==CONSTANTS::LEFT_UP){
                 painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.lu4);
            }
            else if(gameBoard[i][j]==CONSTANTS::UP_RIGHT){
                 painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.ur5);
            }
            else if(gameBoard[i][j]==CONSTANTS::DOWN_RIGHT){
                 painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.dr6);
            }
            else if(gameBoard[i][j]==CONSTANTS::STUMP){
                 painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.stump);
            }
    }
}
    if(!waveStarted){
        for(size_t i = 0, n = CONSTANTS::B_ROWS; i < n; i++){
            if (gameBoard[i][0] == CONSTANTS::ACROSS)
                painter->drawPixmap(0,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.start);
        }
    }
}
}

// draws the bottom of game (pause, lives, money etc.)
void Draw::drawTop(bool loaded, int money, int lives, int wave_num, int speed){

    if(loaded){

    QPen *pen = new QPen();
    pen->setWidth(5);
    pen->setColor(Qt::black);
    painter->setPen(*pen);

    // DRAWS FILLED BLUE RECT AT BOTTOM
    QRect rect (0,CONSTANTS::T_SIZE*CONSTANTS::B_ROWS,CONSTANTS::SCREEN_WIDTH,CONSTANTS::SCREEN_HEIGHT-(CONSTANTS::B_ROWS*CONSTANTS::T_SIZE));
    painter->fillRect(rect, QColor(128, 128, 255, 128));

    // DRAW LINE BORDERING GAME
    painter->drawLine(0,CONSTANTS::T_SIZE*CONSTANTS::B_ROWS,CONSTANTS::SCREEN_WIDTH,CONSTANTS::T_SIZE*CONSTANTS::B_ROWS);
    // DRAW HEART AND COIN PICS AT BOTTOM
    painter->drawPixmap(50,CONSTANTS::B_ROWS*CONSTANTS::T_SIZE+30,25,25,*p.heart_pic);
    painter->drawPixmap(200,CONSTANTS::B_ROWS*CONSTANTS::T_SIZE+30,25,25,*p.coin_pic);

    // DRAW NUMBER OF LIVES AND MONEY TO SCREEN
    QString wavenumber = QString::number(wave_num+1);
    QString wavedisplay("Wave: "+wavenumber);
    painter->setPen(*pen);
    painter->drawText(230,CONSTANTS::B_ROWS*CONSTANTS::T_SIZE+45,QString::number(money));
    painter->drawText(350,CONSTANTS::B_ROWS*CONSTANTS::T_SIZE+45,wavedisplay);
    painter->drawText(80,CONSTANTS::B_ROWS*CONSTANTS::T_SIZE+45,QString::number(lives));

    // DRAWS QUESTION BUTTON
    painter->drawPixmap((CONSTANTS::B_COLS-3)*CONSTANTS::T_SIZE,CONSTANTS::B_ROWS*CONSTANTS::T_SIZE+15,CONSTANTS::SYMB_SIZE,CONSTANTS::SYMB_SIZE,*p.question);

    // DRAWS SPEED BUTTON DEPENDING ON SPEEDS
    if(speed == 0){
        painter->drawPixmap((CONSTANTS::B_COLS-2)*CONSTANTS::T_SIZE,CONSTANTS::B_ROWS*CONSTANTS::T_SIZE+15,CONSTANTS::SYMB_SIZE,CONSTANTS::SYMB_SIZE,*p.speed1);
    }
    else if(speed == 1){
        painter->drawPixmap((CONSTANTS::B_COLS - 2)*CONSTANTS::T_SIZE,CONSTANTS::B_ROWS*CONSTANTS::T_SIZE+15,CONSTANTS::SYMB_SIZE,CONSTANTS::SYMB_SIZE,*p.speed2);
    }
    else if(speed == 2){
        painter->drawPixmap((CONSTANTS::B_COLS - 2)*CONSTANTS::T_SIZE,CONSTANTS::B_ROWS*CONSTANTS::T_SIZE+15,CONSTANTS::SYMB_SIZE,CONSTANTS::SYMB_SIZE,*p.speed3);
    }
            // DRAW PAUSE BUTTON
        painter->drawPixmap(11*CONSTANTS::T_SIZE,CONSTANTS::B_ROWS*CONSTANTS::T_SIZE+15,CONSTANTS::SYMB_SIZE,CONSTANTS::SYMB_SIZE,*p.pause);
    }
}

// DRAWS THE TOWERS IF PLACED AND THEIR ANIMATIONS
void Draw::drawTowers(bool loaded, Tile gameBoard[][CONSTANTS::B_COLS]){
    if (loaded){
        for(size_t i = 0, n = CONSTANTS::B_COLS; i < n; i++){ 
            for(size_t j = 0, n = CONSTANTS::B_ROWS; j < n; j++){ 
                if(gameBoard[i][j].airID==CONSTANTS::M_TREE_ID){
                    painter->drawPixmap(j*CONSTANTS::T_SIZE,(i-1)*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,2*CONSTANTS::T_SIZE,*p.mTree);
                }
                // SQUIRREL
                else if(gameBoard[i][j].airID==CONSTANTS::SQUIRREL_ID){

                    if(gameBoard[i][j].charge<CONSTANTS::CHARGE_TIME/3){
                         painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.squirrel);

                    }
                    else if(gameBoard[i][j].charge>=CONSTANTS::CHARGE_TIME/3 && gameBoard[i][j].charge<CONSTANTS::CHARGE_TIME*2/3 )
                     painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.squirrel2);
                    else
                        painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.squirrel3);

                 }
                // PORCUPINE
                else if(gameBoard[i][j].airID==CONSTANTS::PORCUPINE_ID){
                    if(gameBoard[i][j].charge<CONSTANTS::CHARGE_TIME/3){

                         painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.porcupine);

                    }
                    else if(gameBoard[i][j].charge>=CONSTANTS::CHARGE_TIME/3 && gameBoard[i][j].charge<CONSTANTS::CHARGE_TIME*2/3 )
                     painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.porcupine2);
                    else
                        painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.porcupine3);

                 }
                // SPIDER
                else if(gameBoard[i][j].airID==CONSTANTS::SPIDER_ID){

                    if(gameBoard[i][j].charge<CONSTANTS::CHARGE_TIME/3){
                         painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.spider);
                    }
                    else if(gameBoard[i][j].charge>=CONSTANTS::CHARGE_TIME/3 && gameBoard[i][j].charge<CONSTANTS::CHARGE_TIME*2/3 )
                     painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.spider2);
                    else
                        painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.spider3);

                }
                // FROG
                else if(gameBoard[i][j].airID==CONSTANTS::FROG_ID){
                    if(gameBoard[i][j].charge<CONSTANTS::CHARGE_TIME/3){
                         painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.frog);

                    }
                    else if(gameBoard[i][j].charge>=CONSTANTS::CHARGE_TIME/3 && gameBoard[i][j].charge<CONSTANTS::CHARGE_TIME*2/3 )
                         painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.frog2);
                    else if(gameBoard[i][j].charge>=CONSTANTS::CHARGE_TIME*2/3 )
                        painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.frog3);

                    if(gameBoard[i][j].isShooting){
                        painter->drawPixmap(j*CONSTANTS::T_SIZE,i*CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.frog3);
                        gameBoard[i][j].isShooting = false;
                    }

               }
            }
         }
     }
}
void Draw::drawMen(Wave waves[], int wave_num){

for (size_t i = 0 , n = CONSTANTS::MAX_ENEM; i < n ; i++){ 
    if(waves[wave_num].enemies[i].inGame){

        if(waves[wave_num].enemies[i].framewalk % 4 == 0){
            if(waves[wave_num].enemies[i].type == 1)
                painter->drawPixmap(waves[wave_num].enemies[i].x+CONSTANTS::MEN_MARG,waves[wave_num].enemies[i].y+CONSTANTS::MEN_MARG, 40,40,*p.man);
            else if(waves[wave_num].enemies[i].type == 2)
                painter->drawPixmap(waves[wave_num].enemies[i].x+CONSTANTS::MEN_MARG,waves[wave_num].enemies[i].y+CONSTANTS::MEN_MARG, 40,40,*p.hatman);
            else if(waves[wave_num].enemies[i].type == 3)
                painter->drawPixmap(waves[wave_num].enemies[i].x,waves[wave_num].enemies[i].y, CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.dozer);
            else if(waves[wave_num].enemies[i].type == 4)
                painter->drawPixmap(waves[wave_num].enemies[i].x,waves[wave_num].enemies[i].y, CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.jackman1);
        }
        else if(waves[wave_num].enemies[i].framewalk % 4 == 1){
            if(waves[wave_num].enemies[i].type == 1)
                painter->drawPixmap(waves[wave_num].enemies[i].x+CONSTANTS::MEN_MARG,waves[wave_num].enemies[i].y+CONSTANTS::MEN_MARG, 40,40,*p.man2);
            else if(waves[wave_num].enemies[i].type == 2)
                painter->drawPixmap(waves[wave_num].enemies[i].x+CONSTANTS::MEN_MARG,waves[wave_num].enemies[i].y+CONSTANTS::MEN_MARG, 40,40,*p.hatman2);
            else if(waves[wave_num].enemies[i].type == 3)
                painter->drawPixmap(waves[wave_num].enemies[i].x,waves[wave_num].enemies[i].y, CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.dozer2);
            else if(waves[wave_num].enemies[i].type == 4)
                painter->drawPixmap(waves[wave_num].enemies[i].x,waves[wave_num].enemies[i].y, CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.jackman2);
        }
        else if(waves[wave_num].enemies[i].framewalk % 4 == 2){
            if(waves[wave_num].enemies[i].type == 1)
                painter->drawPixmap(waves[wave_num].enemies[i].x+CONSTANTS::MEN_MARG,waves[wave_num].enemies[i].y+CONSTANTS::MEN_MARG, 40,40,*p.man3);
            else if(waves[wave_num].enemies[i].type == 2)
                painter->drawPixmap(waves[wave_num].enemies[i].x+CONSTANTS::MEN_MARG,waves[wave_num].enemies[i].y+CONSTANTS::MEN_MARG, 40,40,*p.hatman3);
            else if(waves[wave_num].enemies[i].type == 3)
                painter->drawPixmap(waves[wave_num].enemies[i].x,waves[wave_num].enemies[i].y, CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.dozer3);
            else if(waves[wave_num].enemies[i].type == 4)
                painter->drawPixmap(waves[wave_num].enemies[i].x,waves[wave_num].enemies[i].y, CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.jackman1);
        }
        else{
            if(waves[wave_num].enemies[i].type == 1)
                painter->drawPixmap(waves[wave_num].enemies[i].x+CONSTANTS::MEN_MARG,waves[wave_num].enemies[i].y+CONSTANTS::MEN_MARG, 40,40,*p.man4);
            else if(waves[wave_num].enemies[i].type == 2)
                painter->drawPixmap(waves[wave_num].enemies[i].x+CONSTANTS::MEN_MARG,waves[wave_num].enemies[i].y+CONSTANTS::MEN_MARG, 40,40,*p.hatman4);
            else if(waves[wave_num].enemies[i].type == 3)
                painter->drawPixmap(waves[wave_num].enemies[i].x,waves[wave_num].enemies[i].y, CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.dozer2);
            else if(waves[wave_num].enemies[i].type == 4)
                painter->drawPixmap(waves[wave_num].enemies[i].x,waves[wave_num].enemies[i].y, CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.jackman2);
        }

        }
    }
}
void Draw::drawHealth(Wave waves[],int wave_num){
    for(size_t i = 0, n = CONSTANTS::MAX_ENEM; i< n; i++){ 
        int health = waves[wave_num].enemies[i].hp;
        if(waves[wave_num].enemies[i].inGame){
            QPen *pen = new QPen();
            pen->setWidth(2);
            pen->setColor(Qt::red);
            painter->setPen(*pen);
            // DRAWS RED LINE AT LENGTH 20(CONST)
            painter->drawLine(waves[wave_num].enemies[i].rect->x(),waves[wave_num].enemies[i].y-CONSTANTS::MEN_MARG,waves[wave_num].enemies[i].rect->x()+CONSTANTS::HP_LEN,waves[wave_num].enemies[i].y-CONSTANTS::MEN_MARG);
            pen->setColor(Qt::green);
            painter->setPen(*pen);
            // DRAWS RED LINE OVER AT LENGTH PROPORTONAL TO HEALTH
            if(waves[wave_num].enemies[i].type==CONSTANTS::MAN_ID)
               painter->drawLine(waves[wave_num].enemies[i].rect->x(),waves[wave_num].enemies[i].y-CONSTANTS::MEN_MARG,waves[wave_num].enemies[i].rect->x()+health/(CONSTANTS::MAN_HP/CONSTANTS::HP_LEN),waves[wave_num].enemies[i].y-CONSTANTS::MEN_MARG);
            else if(waves[wave_num].enemies[i].type==CONSTANTS::H_MAN_ID)
               painter->drawLine(waves[wave_num].enemies[i].rect->x(),waves[wave_num].enemies[i].y-CONSTANTS::MEN_MARG,waves[wave_num].enemies[i].rect->x()+health/(CONSTANTS::H_MAN_HP/CONSTANTS::HP_LEN),waves[wave_num].enemies[i].y-CONSTANTS::MEN_MARG);
            else if(waves[wave_num].enemies[i].type==CONSTANTS::DOZER_ID)
               painter->drawLine(waves[wave_num].enemies[i].rect->x(),waves[wave_num].enemies[i].y-CONSTANTS::MEN_MARG,waves[wave_num].enemies[i].rect->x()+health/(CONSTANTS::DOZER_HP/CONSTANTS::HP_LEN),waves[wave_num].enemies[i].y-CONSTANTS::MEN_MARG);
            else if(waves[wave_num].enemies[i].type==CONSTANTS::JACKMAN_ID)
               painter->drawLine(waves[wave_num].enemies[i].rect->x(),waves[wave_num].enemies[i].y-CONSTANTS::MEN_MARG,waves[wave_num].enemies[i].rect->x()+health/(CONSTANTS::JACK_MAN_HP/CONSTANTS::HP_LEN),waves[wave_num].enemies[i].y-CONSTANTS::MEN_MARG);
        pen->setWidth(3);
        pen->setColor(Qt::black);
        painter->setPen(*pen);
        }
    }

}
// DRAWS UPGRADE/SELL OPTIONS WHEN USER CLICKS ON A TOWER
void Draw::drawUpgrade(Tile gameBoard[][CONSTANTS::B_COLS],bool towerClicked){
    if(towerClicked){
        for(size_t i = 0, n = CONSTANTS::B_COLS; i < n; i++){ 
            for(size_t j = 0, n = CONSTANTS::B_ROWS; j < n; j++){ 

                if(gameBoard[i][j].isClicked){
                    QString upCost = QString::number(gameBoard[i][j].upgradeCost);
                    QString sell = QString::number(gameBoard[i][j].towerCost/2);
                    // DRAW THE TOWER RANGE IF SELECTED
                    if(gameBoard[i][j].airID != CONSTANTS::NOTHING  && gameBoard[i][j].airID != 0){
                        QPoint p(gameBoard[i][j].towerRange.x(),gameBoard[i][j].towerRange.y());
                        painter->drawEllipse(p,gameBoard[i][j].towerRange.getR(),gameBoard[i][j].towerRange.getR());
                    }
                    // HIGHLIGHTS SELECTED TOWER
                    painter->drawPixmap(gameBoard[i][j].xC,gameBoard[i][j].yC, CONSTANTS::T_SIZE,CONSTANTS::T_SIZE, *p.shine); 
                    // DRAWS THE BUTTONS FOR SELLING, UPGRADING AND CANCELLING
                    painter->drawPixmap(gameBoard[i][j].xC+10,gameBoard[i][j].yC+CONSTANTS::T_SIZE, CONSTANTS::SYMB_SIZE,CONSTANTS::SYMB_SIZE, *p.cancel);
                    painter->drawPixmap(gameBoard[i][j].xC-40,gameBoard[i][j].yC-CONSTANTS::T_SIZE/2, CONSTANTS::SYMB_SIZE,CONSTANTS::SYMB_SIZE, *p.sell);
                    painter->drawPixmap(gameBoard[i][j].xC+55,gameBoard[i][j].yC-CONSTANTS::T_SIZE/2, CONSTANTS::SYMB_SIZE,CONSTANTS::SYMB_SIZE, *p.upgrade);
                    painter->drawText(gameBoard[i][j].xC+70,gameBoard[i][j].yC+30,upCost);
                    painter->drawText(gameBoard[i][j].xC-20,gameBoard[i][j].yC+30,sell);

                }
            }

    }
}
}

// DRAWS TOWER SELECTION IF USER CLICKS ON PLACEABLE TILE
void Draw::drawPick(bool towerPick,Tile gameBoard[][12] ){
    if(towerPick){
         for(size_t i = 0, n = CONSTANTS::B_COLS; i < n; i++){ 
            for(size_t j = 0, n = CONSTANTS::B_ROWS; j < n; j++){ 
                if(gameBoard[i][j].isClicked){
                    painter->drawPixmap(gameBoard[i][j].xC,gameBoard[i][j].yC, CONSTANTS::T_SIZE,CONSTANTS::T_SIZE, *p.shine);
                    painter->drawPixmap(gameBoard[i][j].xC-CONSTANTS::T_SIZE,gameBoard[i][j].yC-CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.sPick);
                    painter->drawPixmap(gameBoard[i][j].xC+CONSTANTS::T_SIZE,gameBoard[i][j].yC-CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.pPick);
                    painter->drawPixmap(gameBoard[i][j].xC-CONSTANTS::T_SIZE,gameBoard[i][j].yC+CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.spidPick);
                    painter->drawPixmap(gameBoard[i][j].xC+CONSTANTS::T_SIZE,gameBoard[i][j].yC+CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,CONSTANTS::T_SIZE,*p.fPick);
                }
            }
            }
    }
}

// DRAWS WEBS OVER ENEMIES IF THEY ARE SLOWED
void Draw::drawWebs(Wave waves[], int wave_num){
    for(size_t i = 0, n = CONSTANTS::MAX_ENEM; i < n; i++){
        if(waves[wave_num].enemies[i].isSlowed){
            painter->drawPixmap(waves[wave_num].enemies[i].x,waves[wave_num].enemies[i].y, CONSTANTS::SYMB_SIZE,CONSTANTS::SYMB_SIZE, *p.web);
        }
    }
}

// draws acorns thrown at enemies
// ALSO DRAWS FROGS BEAM
// ALSO DRAWS PORCUPINES NEEDLES
void Draw::drawAcorns(Tile gameBoard[][CONSTANTS::B_COLS]){
    for(size_t i = 0, n = CONSTANTS::B_ROWS; i < n; i++){ 
       for(size_t j = 0, n = CONSTANTS::B_COLS; j < n; j++){ 
            if(gameBoard[i][j].acorn.inGame){
                // IF A FROG DRAW YELLOW LINE
                if(gameBoard[i][j].airID==CONSTANTS::FROG_ID){
                    QPen* pen = new QPen();
                    pen->setColor(Qt::yellow);
                    pen->setWidth(4);
                    painter->setPen(*pen);
                    gameBoard[i][j].acorn.drawShots2();
                    pen->setColor(Qt::black);
                    pen->setWidth(3);
                    painter->setPen(*pen);
                }
                // ELSE DRAW ACORNS
                else{
                gameBoard[i][j].acorn.drawShots();}

            }
            // IF PORCUPINE NEEDLES ARE IN GAME DRAW THEM
            else if(gameBoard[i][j].needles.inGame){
               gameBoard[i][j].needles.drawShots();
            }
        }
    }
}

// DRAWS RESUME/ QUIT MENU WHEN GAME IS PAUSED
void Draw::drawMenu(bool started){
    if(!started){
        // DRAWS BLACK BACKGROUND BOX
        QRect box(CONSTANTS::SCREEN_WIDTH/3,150,250,375);
        painter->fillRect(box, Qt::gray);
        painter->drawRect(CONSTANTS::SCREEN_WIDTH,150,250,375);
        
        painter->drawPixmap(350,200,150,75,*p.resumeButton);
        painter->drawPixmap(350,300,150,75,*p.quitButton);
        painter->drawPixmap(350,400,150,75,*p.restartButton);

    }
}
