#include "enemy.h"

Enemy::Enemy()
{
    eraseEnemy();   
    direction = ATTRIBUTES::RIGHT;      // ALL ENEMIES BEGIN MOVING RIGHT
    hp = CONSTANTS::MAN_HP;             // initilize regular man qualities
    type = CONSTANTS::MAN_ID;
    speed = ATTRIBUTES::MAN_SPD;
    inGame = false;
    isSlowed = false;
    dead = false;
}

void Enemy::spawn(int array [][CONSTANTS::B_COLS] , int length, int eID){
    for(size_t i = 0, n = length; i < n; i++){
        // check first column of tiles. Spawn at tile that starts across
        int id = array[i][0];                       
                if(id == CONSTANTS::ACROSS){        
                    framewalk = 0;
                    xTile = 0;          // start enemy in first walk tile
                    yTile = i;
                    x = 0;                      // x coord is 0, y is number of tiles times the size of tile
                    y = i*CONSTANTS::T_SIZE;
                    // rect is the hitbox for enemy. It is shifted to account for image size
                    rect = new QRect(x+ATTRIBUTES::BIG_MAR,y+ATTRIBUTES::SML_MAR,ATTRIBUTES::SMALL_X,ATTRIBUTES::SMALL_Y);
                    type = eID;
                    // set values according to enemy type
                    if(type == CONSTANTS::H_MAN_ID){
                        setHardHat();
                        rect = new QRect(x+ATTRIBUTES::BIG_MAR,y+ATTRIBUTES::SML_MAR,ATTRIBUTES::SMALL_X,ATTRIBUTES::SMALL_Y);
                    }
                    if(type == CONSTANTS::DOZER_ID){
                        setDozer();

                    }
                    if(type==CONSTANTS::JACKMAN_ID){
                        setJack();
                    }
                }
    inGame = true;          // set in game
}

}

void Enemy::setHardHat(){
    hp = CONSTANTS::H_MAN_HP;
    speed = ATTRIBUTES::H_MAN_SPD;
}

void Enemy::setDozer(){
    hp = CONSTANTS::DOZER_HP;
    speed = ATTRIBUTES::DOZER_SPD;
    rect = new QRect(x+ATTRIBUTES::SML_MAR,y+ATTRIBUTES::SML_MAR,ATTRIBUTES::BIG_X,ATTRIBUTES::BIG_Y);

}

void Enemy::setJack(){
    hp = CONSTANTS::JACK_MAN_HP;
    speed = ATTRIBUTES::JACK_MAN_SPD;
     rect = new QRect(x+ATTRIBUTES::SML_MAR,y+ATTRIBUTES::SML_MAR,ATTRIBUTES::BIG_X,ATTRIBUTES::BIG_Y);
}

// function that moves individual enemy through the gameboard
// passes in number of lives variable to keep track of escaped men

void Enemy::move(int array[][CONSTANTS::B_COLS], int array2 [][CONSTANTS::B_COLS], int &lives){
    if(isSlowed&&stopTime<=0){
        isSlowed = false;
        if(CONSTANTS::MAN_ID==type)
        speed = ATTRIBUTES::MAN_SPD;
        else if(CONSTANTS::H_MAN_ID==type)
        speed = ATTRIBUTES::H_MAN_SPD;
        else if(CONSTANTS::DOZER_ID==type)
        speed = ATTRIBUTES::DOZER_SPD;
        else if(CONSTANTS::JACKMAN_ID==type)
        speed = ATTRIBUTES::JACK_MAN_SPD;

    }
    // walk in same direction while walkLength is less than one tile, when enemy
    // reaches length of one tile, check to find next path to take
                 if(direction == ATTRIBUTES::RIGHT){
                     if(speed+walkLength>CONSTANTS::T_SIZE){
                         x+=(CONSTANTS::T_SIZE-walkLength);
                     }
                     else
                     {
                          x += speed;
                     }

                    rect->moveLeft(x+ATTRIBUTES::BIG_MAR);          // must readjust rect with every movement
                     framewalk++;
                }
                else if(direction == ATTRIBUTES::UP){
                     if(speed+walkLength>CONSTANTS::T_SIZE){
                            y-=(CONSTANTS::T_SIZE-walkLength);
                        }
                     else
                        {
                            y-= speed;
                        }
                   rect->moveTop(y+ATTRIBUTES::SML_MAR);
                   framewalk++;
                }
                else if (direction == ATTRIBUTES::DOWN){
                      if(speed+walkLength>CONSTANTS::T_SIZE){
                             y+=(CONSTANTS::T_SIZE-walkLength);
                         }
                      else
                         {
                             y+= speed;
                         }
                  rect->moveTop(y+ATTRIBUTES::SML_MAR);
                  framewalk++;
                }

                else {
                    if (direction == ATTRIBUTES::LEFT){
                       if(speed+walkLength>CONSTANTS::T_SIZE){
                           x-=(CONSTANTS::T_SIZE-walkLength);
                       }
                       else
                       {
                            x -= speed;
                       }
                   rect->moveLeft(x+ATTRIBUTES::BIG_MAR);
                   framewalk++;
                    }
                }
        stopTime --;
        walkLength+=speed;
        if (walkLength > CONSTANTS::T_SIZE){
                    walkLength = CONSTANTS::T_SIZE;
                }
        // looks for next direction
        if(walkLength == CONSTANTS::T_SIZE){
            if(direction == ATTRIBUTES::RIGHT){
                            xTile+=1;
                            prevRight = true;
                        }
                        else if(direction == ATTRIBUTES::UP){
                            yTile-= 1;
                            prevUp = true;
                        }
                        else if (direction == ATTRIBUTES::DOWN){
                            yTile += 1;
                            prevDown = true;
                        }
                        else if(direction == ATTRIBUTES::LEFT){
                            xTile -= 1;
                            prevLeft = true;
                        }

                            if(!prevUp){
                            try{
                                if(array[yTile+1][xTile]!=CONSTANTS::REG_TREE  && array[yTile+1][xTile]!= CONSTANTS::STUMP){
                                    direction = ATTRIBUTES::DOWN;
                                }

                            }catch(std::exception e){}
                            }

                            if(!prevDown){
                            try{
                                if(array[yTile-1][xTile] != CONSTANTS::REG_TREE && array[yTile-1][xTile]!= CONSTANTS::STUMP){
                                    direction = ATTRIBUTES::UP ;
                                }

                                }catch(std::exception e){}
                            }

                            if(!prevLeft){
                            try{
                                if(array[yTile][xTile+1] != CONSTANTS::REG_TREE && array[yTile][xTile+1]!= CONSTANTS::STUMP){
                                    direction = ATTRIBUTES::RIGHT;
                                }

                                }catch(std::exception e){}
                            }
                            if(!prevRight){
                                try{
                                    if(array[yTile][xTile-1] != CONSTANTS::REG_TREE && array[yTile][xTile-1]!= CONSTANTS::STUMP){
                                        direction = ATTRIBUTES::LEFT;
                                    }

                                    }catch(std::exception e){}
                                }
                            // if enemy reaches end, erase him and subtract a life
                        if(array2[yTile][xTile]==CONSTANTS::M_TREE_ID){
                            eraseEnemy();
                            lives--;
                        }

                        prevRight = false;
                        prevLeft = false;
                        prevDown = false;
                        prevUp = false;
                        walkLength = 0;


        }

    }

// takes away certain amount of health
void Enemy::damaged(int dmg){
    if(inGame)
    hp -= dmg;
}

// take enemy out of game
void Enemy::eraseEnemy(){
    inGame = false;
    dead = true;
    isSlowed = false;
    direction = ATTRIBUTES::RIGHT;
    walkLength = 0;
    hp = CONSTANTS::MAN_HP;
}

// enemy is stopped
void Enemy::slowed(){
    isSlowed = true;
    stopTime = ATTRIBUTES::DURATION;
    speed = ATTRIBUTES::SLOW_SPD;
}

bool Enemy::checkDeath(){
    if(inGame){
    if (hp<=0){
        dead = true;
        eraseEnemy();
        return true;
    }
    }
        return false;
}
