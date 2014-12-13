#ifndef WAVE_H
#define WAVE_H

#include "enemy.h"
#include "stages.h"
#include "constants.h"

#include <QDebug>
class Wave
{
public:
    Wave();
    Wave(int id, int array[][12]);
    void set_wave(int id);
    void spawn();
    bool roundOver();
    void start();

    Enemy enemies[50];
    bool started;
    bool ready;
    bool finished;
    int wave_id;
    int spawntime;
    int spawnframe;
    int map[8][12];
    Stages stages;

};

#endif // WAVE_H
