#include "stages.h"

Stages::Stages()
{
    define();
}

void Stages::define(){

    // level 1
    for(int i =0; i<20; i++){
        levels[0][i]=1;
    }
    levels[0][50]=20;

    //level 2
    for(int i = 0; i < 20; i++){
        if(i<10)
            levels[1][i] = 1;
        else
            levels[1][i] = 2;
    }
    levels[1][50]=20;

    // level 3
    for(int i = 0; i < 20; i++){
        levels[2][i] = 2;
    }
    levels[2][50]=20;

    // level4
    for(int i = 0; i < 30; i++){
        if(i<20)
        levels[3][i]=2;
        else
            levels[3][i]=1;
    }
    levels[3][50]=30;

    // level5
    for(int i =0; i < 20; i++){
        if(i<3)
            levels[4][i]=3;
        else
            levels[4][i]=1;
    }
    levels[4][50]=20;

    // level6
    for(int i =0; i < 20; i++){
        if(i<10)
            levels[5][i]=1;
        else
            levels[5][i]=4;
    }
    levels[5][50]=20;

    // level7
    for(int i =0; i < 40; i++){
        if(i == 10 || i == 20 || i == 30)
            levels[6][i]=3;
        else
            levels[6][i]=4;
    }
    levels[6][50]=40;

    // level8
    for(int i =0; i < 40; i++){
        if(i % 2 == 1)
            levels[7][i]=2;
        else
            levels[7][i]=4;
    }
    levels[7][50]=40;

    // level9
    for(int i =0; i < 20; i++){

            levels[8][i]=3;
    }
    levels[8][50]=20;

    // level10
    for(int i =0; i < 45; i++){
            if(i<20)
            levels[9][i]=3;
            else
                 levels[9][i]=4;
    }
    levels[9][50]=45;
}
