#include "wave.h"
Wave::Wave(){
    started = false;
    ready = false;
    finished = false;
    spawntime = 200;
    spawnframe = 0;
}

Wave::Wave(int id,int array [][12])
{
    wave_id = id;
    started = false;
    ready = false;
    finished = false;

    set_wave(wave_id);
    spawntime = 200;
    spawnframe = 0;

    for(int i = 0; i < 8; i ++){
        for (int j=0; j < 12; j ++){
            map[i][j]=array[i][j];
        }
    }

}


void Wave::set_wave(int id){
        ready =true;
        started = false;
}

void Wave::start(){
    started = true;
}

void Wave::spawn(){
    if(started&&ready){
        for(int i = 0; i < 20; i++){
            if(spawnframe >= spawntime){

                for(int j = 0; j < stages.levels[wave_id][50]; j++){
                    if(!enemies[j].inGame && !enemies[j].dead){

                            enemies[j].spawn(map,8,stages.levels[wave_id][j]);

                        break;
                    }
                }
                spawnframe = 0;
           }
            else{
                spawnframe += 1;
            }
        }
    }
}
bool Wave::roundOver(){
    int count = 0;                      // number dead

    for(int i = 0 ; i < stages.levels[wave_id][50]; i ++){
       if(enemies[i].dead){
           count++;
       }

    }
    if(count==stages.levels[wave_id][50]){
        finished = true;
        return true;
    }
    else{
        return false;
    }
}
