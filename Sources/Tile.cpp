#include "tile.h"

Tile::Tile()
{
    xC = 0;
    yC = 0;
    size = 75;
    groundID = 0;
    airID = -1;
    chargeRate = 0;
    chargeTime = 1000;
    charge = 0;
    isShooting = false;
    enemyNum = 0;
    isClicked = false;
    towerLevel = 1;
    towerCost = 0;
    upgradeCost = 0;
    damage = 0;

}

void Tile::setPainter(QPainter *p){
    painter = p;
}

void Tile::set_values(int x, int y, int gid, int aid){
    xC = x;
    yC = y;
    groundID = gid;
    airID = aid;
    towerRange.setValues(x+size/2,y+size/2,100);

}

void Tile::set_range(int x){
    towerRange.setValues(xC+size/2,yC+size/2,x);
}

void Tile::set_air(int air){
    airID = air;
    if(air==2){
        set_range(150);
        towerCost+=50;
        chargeRate = 40;
        upgradeCost = 100;
        damage = 20;
    }
    if(air==3){
        set_range(100);
        towerCost+=150;
        chargeRate = 20;
        upgradeCost = 150;
        damage = 30;
    }
    if(air==4){
        set_range(125
                  );
        towerCost+=100;
        chargeRate = 20;
        upgradeCost = 100;

    }
    if(air==5){
        set_range(200);
        towerCost+=200;
        chargeRate = 20;
        upgradeCost = 150;
        damage = 100;
    }
}

void Tile::subtract(Enemy e){
    charge = 0;
    QString ac("/Users/Will/Desktop/pic10c/acorn.png");
        QPixmap *acorns = new QPixmap(ac);

    if(!acorn.inGame){
        acorn.fire(xC,yC,e.rect->x()+20,e.rect->y()+10,*acorns,painter);
    }
}

void Tile::spreadFire(Enemy e [50]){
    charge = 0;
    if(!needles.inGame){
        needles.fire(xC+size/2,yC+size/2,painter);
    }
    for (int i = 0; i < 50; i ++){
        if(e[i].inGame){
        if (towerRange.intersects(e[i].rect)){
            e[i].damaged(damage);
        }
        }
    }
}

void Tile::attack(Enemy enemies [50]){
    if(airID==2){

            for (int i = 0; i < 50; i++){

            if(enemies[i].inGame){
                if(towerRange.intersects(enemies[i].rect) && charge>=chargeTime){
                    isShooting = true;
                    enemyNum = i;
                    enemyX =  enemies[i].x;
                    enemyY = enemies[i].y;
                    enemies[i].damaged(damage);
                    subtract(enemies[i]);
                    break;
                }
            }
        }
            charge += chargeRate;
    }
    if(airID==3){
        for (int i = 0; i < 50; i++){
        if(enemies[i].inGame){
            if(towerRange.intersects(enemies[i].rect) && charge>=chargeTime){
                isShooting = true;
                spreadFire(enemies);
                break;
            }

         }
       }

        charge += chargeRate;
    }
    if(airID==4){

            for (int i = 0; i < 50; i++){

            if(enemies[i].inGame){
                if(towerRange.intersects(enemies[i].rect) && charge>=chargeTime){
                    isShooting = true;
                    enemyNum = i;
                    enemyX =  enemies[i].x;
                    enemyY = enemies[i].y;
                    enemies[i].slowed();
                    charge = 0;
                    break;
                }

            }
        }
            charge += chargeRate;
    }
    if(airID==5){

            for (int i = 0; i < 50; i++){

            if(enemies[i].inGame){
                if(towerRange.intersects(enemies[i].rect) && charge>=chargeTime){
                    isShooting = true;
                    enemyNum = i;
                    enemyX =  enemies[i].x;
                    enemyY = enemies[i].y;
                    enemies[i].damaged(damage);
                    subtract(enemies[i]);                
                  break;
                }

            }
        }
            charge += chargeRate;
    }
}

void Tile::sellTower(int &money){
    if (airID==2){
        airID = -1;
        towerLevel = 1;
        money+=towerCost/2;

    }
    if (airID==3){
        airID = -1;
        towerLevel = 1;
        money+=towerCost/2;
    }
    if (airID==4){
        airID = -1;
        towerLevel = 1;
        money+=towerCost/2;
    }

    if (airID==5){
        airID = -1;
        towerLevel = 1;
        money+=towerCost/2;
    }

}

void Tile::upgrade(){
    if (airID==2){
    chargeRate += 50;
    towerCost+=upgradeCost;
    upgradeCost += upgradeCost/2;
    damage+=10;

    }
    if (airID==3){
        chargeRate += 10;
         towerCost+=upgradeCost;
        upgradeCost += upgradeCost/2;
        damage+=10;
    }
    if (airID==4){
        chargeRate += 10;
         towerCost+=upgradeCost;
        upgradeCost += upgradeCost/2;

    }

    if (airID==5){
        chargeRate += 10;
         towerCost+=upgradeCost;
        upgradeCost += upgradeCost/2;
        damage+=100;
    }
}
