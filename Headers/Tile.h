#ifndef TILE_H
#define TILE_H
#include "circle.h"
#include "enemy.h"
#include "projectiles.h"
#include "needles.h"
#include "constants.h"

#include <QPainter>
#include <QDebug>

// tile class
// Used by gameboard to draw map, hold towers

class Tile
{
public:
    Tile();
    void set_values(int x, int y, int gid, int aid);
    void set_air(int air);
    void set_range(int x);
    void subtract(Enemy e);
    void spreadFire(Enemy e [50]);
    void setPainter(QPainter *p);
    void sellTower(int & money);
    void upgrade();

    int charge;
    int groundID;
    int airID;
    int size;
    int xC;
    int yC;
    int towerLevel;
    int towerCost;
    int upgradeCost;
    int damage;
    int chargeTime;

    void attack(Enemy enemies [50]);

    Circle towerRange;
    bool isShooting;
    int enemyX;
    int enemyY;
    int frame_throw;
    int frames;

    int enemyNum;
    Projectiles acorn;
    Needles needles;

    bool isClicked;

private:

    int chargeRate;

    QPainter *painter;


};

#endif // TILE_H
