#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    newGame();

    }

void GameWindow::newGame(){
    towerClicked = false;
    towerPick = false;
    started = true;
    gameStart = false;
    wave_num = 0;
    diff = 1;
    countloss = 0;
    userLost = false;
    speedChange = 0;
    lives = GAME_CONST::START_LIVES1;
    draw.setPainter(myPaint);
    money = GAME_CONST::START_MON1;
    this->setFixedSize(CONSTANTS::SCREEN_WIDTH,CONSTANTS::SCREEN_HEIGHT);
    loaded = false;
    timer = new QTimer(this);
    timer->setSingleShot(false);
    connect(timer, SIGNAL(timeout()), this, SLOT(redraw()));
    timer->start(100);
}

void GameWindow::newGame(int level, int difficulty){
    newGame();
    if(difficulty==3)
        setDif3();
    else if(difficulty==2)
        setDif2();
    else
        setDif1();

    if(level==1){
        setL1();
        show();
    }
    else if(level==2){
        setL2();
        show();
    }
    else{
        setL3();
        show();
    }
   }



void GameWindow::changeSpeed(){
    if(speedChange==0){
        timer->stop();
        timer->start(75);
        speedChange++;
    }

    else if(speedChange==1){
        timer->stop();
        timer->start(20);
        speedChange++;
    }
    else if(speedChange==2){
        timer->stop();
        timer->start(100);
        speedChange=0;
    }
}

void GameWindow::setL1(){
    levelPicked = 1;
    gameStart = true;
}
void GameWindow::setL2(){
    levelPicked = 2;
     gameStart = true;
}
void GameWindow::setL3(){
    levelPicked = 3;
     gameStart = true;
}
// loads level
void GameWindow::loadLevel(){
    //backgroundMusic->play();

    int level1 [CONSTANTS::B_ROWS][CONSTANTS::B_COLS] =
                          {        {7,7,7,7,7,7,7,7,7,7,7,7},
                                   {7,0,0,7,0,0,0,0,7,0,0,7},
                                   {7,0,0,0,0,6,1,1,1,1,1,1},
                                   {7,0,7,0,0,2,0,0,0,7,0,7},
                                   {7,0,0,0,0,2,0,7,0,0,0,7},
                                   {7,0,0,7,0,2,0,0,0,0,0,7},
                                   {1,1,1,1,1,4,0,0,7,0,0,7},
                                   {7,0,0,0,0,0,0,0,0,0,0,7} };

    int level2 [CONSTANTS::B_ROWS][CONSTANTS::B_COLS]=
                           {     {7,7,7,7,7,7,7,7,7,7,7,7},
                                 {1,1,3,0,0,0,0,0,7,0,0,7},
                                 {7,0,2,0,7,6,1,1,1,1,1,1},
                                 {7,0,2,0,0,2,0,0,0,7,0,7},
                                 {7,0,2,7,0,2,7,0,0,0,0,7},
                                 {7,0,2,0,0,2,0,0,7,0,0,7},
                                 {7,0,5,1,1,4,0,0,0,0,0,7},
                                 {7,7,7,7,7,7,7,7,7,7,7,7} };

    int level3 [CONSTANTS::B_ROWS][CONSTANTS::B_COLS]=
                           {      {7,7,6,1,1,1,1,1,1,3,7,7},
                                  {7,0,2,0,7,7,0,0,0,2,0,7},
                                  {7,0,2,0,0,0,0,0,0,5,1,1},
                                  {7,0,5,1,1,1,1,3,0,0,0,7},
                                  {7,0,0,0,7,0,0,2,0,7,0,7},
                                  {1,1,1,1,1,1,1,4,0,0,0,7},
                                  {7,0,0,0,0,0,0,0,0,0,0,7},
                                  {7,7,7,7,7,7,7,7,7,7,7,7} };


    int airIds [CONSTANTS::B_ROWS][CONSTANTS::B_COLS] =
                          {        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 1},
                                   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                                   {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}    };

    for(size_t y = 0, n = CONSTANTS::B_ROWS; y < n; y++){
        int Gid;
                for(size_t x = 0, n = CONSTANTS::B_COLS; x < n; x++){
                    if(levelPicked==1)
                 Gid = level1[y][x];
                    if(levelPicked==2)
                 Gid = level2[y][x];
                    if(levelPicked==3)
                 Gid = level3[y][x];
                int Aid = airIds[y][x];
                level_G[y][x] = Gid;
                level_A[y][x] = Aid;

                }
                }

    for(size_t y = 0, n = CONSTANTS::B_ROWS; y < n; y++){
               for(size_t x = 0, n = CONSTANTS::B_COLS; x < n; x++){
                int g = level_G[y][x];
                int a = airIds[y][x];
                gameBoard[y][x].set_values(CONSTANTS::T_SIZE*x,CONSTANTS::T_SIZE*y,g,a);
                }
                }

}

// slot that is recalled
void GameWindow::redraw(){

    if(!loaded && gameStart){

        loadLevel();
        Wave w(wave_num,level_G);
        waves[wave_num] = w;

        loaded = true;
    }
    repaint();

}

// paint event that calls all the draw functions and game mechanics
void GameWindow::paintEvent(QPaintEvent *){

    myPaint = new QPainter(this);
    draw.setPainter(myPaint);

    if(loaded){
        for(size_t i = 0, n = CONSTANTS::B_ROWS; i < n; i++){
                   for(size_t j = 0, n = CONSTANTS::B_COLS; j < n; j++){
                gameBoard[i][j].setPainter(myPaint);
            }
        }

    draw.drawBoard(level_G,waves[wave_num].started,loaded);
    draw.drawTop(loaded,money,lives,wave_num,speedChange);

    if(started){
    spawnMen();
    towerPhysics();
    moveMen();
    }

    draw.drawTowers(loaded,gameBoard);
    draw.drawMen(waves,wave_num);
    draw.drawHealth(waves,wave_num);
    draw.drawWebs(waves,wave_num);
    draw.drawAcorns(gameBoard);
    draw.drawUpgrade(gameBoard,towerClicked);
    draw.drawPick(towerPick,gameBoard);
    draw.drawMenu(started);

    checkWave();
    checkLoss();
    checkKills();
    messageUser();

    // stops timer if paused
    if(!started){
        timer->stop();
    }
    }
}

// checks to see if wave is over, if yes advance to next wave
void GameWindow::checkWave(){
    if(waves[wave_num].roundOver()){
        wave_num++;
        Wave w(wave_num, level_G);
        waves[wave_num] = w;
    }
    if(wave_num>=10){
        userWon();
    }
}

// mouse event that calls all functions pertaining to mouse clicks
void GameWindow::mousePressEvent(QMouseEvent *e){

    int x = e->x();
    int y = e->y();

    // if a empty space is clicked, get coordinates to select tower choice
    if(towerPick){

        for(size_t i = 0, n = CONSTANTS::B_ROWS; i < n; i++){
                   for(size_t j = 0, n = CONSTANTS::B_COLS; j < n; j++){
                if(gameBoard[i][j].isClicked){
                    // pick squirrel
                    if(x>gameBoard[i][j].xC-CONSTANTS::T_SIZE && x<gameBoard[i][j].xC && y<gameBoard[i][j].yC && y>gameBoard[i][j].yC-CONSTANTS::T_SIZE && money >= GAME_CONST::TOWER1COST){
                        towerPick = false;
                        gameBoard[i][j].isClicked = false;
                        gameBoard[i][j].set_air(2);
                        money -= GAME_CONST::TOWER1COST;

                    }
                    // pick porcupine
                   else if(x>gameBoard[i][j].xC+CONSTANTS::T_SIZE && x<gameBoard[i][j].xC+(CONSTANTS::T_SIZE*2) && y<gameBoard[i][j].yC && y>gameBoard[i][j].yC-CONSTANTS::T_SIZE && money >= GAME_CONST::TOWER2COST ){
                        towerPick = false;
                        gameBoard[i][j].isClicked = false;
                        gameBoard[i][j].set_air(3);
                        money -= GAME_CONST::TOWER2COST;

                    }
                    // pick spider
                   else if(x>gameBoard[i][j].xC-CONSTANTS::T_SIZE && x<gameBoard[i][j].xC && y<gameBoard[i][j].yC+(CONSTANTS::T_SIZE*2) && y>gameBoard[i][j].yC+CONSTANTS::T_SIZE && money >= GAME_CONST::TOWER3COST ){
                        towerPick = false;
                        gameBoard[i][j].isClicked = false;
                        gameBoard[i][j].set_air(4);
                        money -= GAME_CONST::TOWER3COST;
                }   // pick frog
                   else if(x>gameBoard[i][j].xC+CONSTANTS::T_SIZE && x<gameBoard[i][j].xC+(CONSTANTS::T_SIZE*2) && y<gameBoard[i][j].yC+(CONSTANTS::T_SIZE*2) && y>gameBoard[i][j].yC+CONSTANTS::T_SIZE && money >= GAME_CONST::TOWER4COST ){
                        towerPick = false;
                        gameBoard[i][j].isClicked = false;
                        gameBoard[i][j].set_air(5);
                        money -= GAME_CONST::TOWER4COST;
                }   // else close pick menu
                    else{
                        towerPick = false;
                        gameBoard[i][j].isClicked = false;
                    }

            }
            }
        }

    }else{
    // select empty tile
        for(size_t i = 0, n = CONSTANTS::B_ROWS; i < n; i++){
                   for(size_t j = 0, n = CONSTANTS::B_COLS; j < n; j++){
            if(!towerClicked && gameBoard[i][j].airID==-1 && gameBoard[i][j].groundID ==0 && y>i*CONSTANTS::T_SIZE && y<(i+1)*CONSTANTS::T_SIZE && x>(j)*CONSTANTS::T_SIZE && x<(j+1)*CONSTANTS::T_SIZE){
                towerPick = true;
                gameBoard[i][j].isClicked = true;
            }

        }
        }

    // UPGRADING
    if(towerClicked ){
        for(size_t i = 0, n = CONSTANTS::B_ROWS; i < n; i++){
                   for(size_t j = 0, n = CONSTANTS::B_COLS; j < n; j++){
                // sell tower
                if(gameBoard[i][j].isClicked){
                    if(x>gameBoard[i][j].xC-40 && x<gameBoard[i][j].xC+10 && y<gameBoard[i][j].yC-CONSTANTS::T_SIZE/2+50 && y>gameBoard[i][j].yC-CONSTANTS::T_SIZE/2 ){
                        towerClicked = false;
                        gameBoard[i][j].isClicked = false;
                        gameBoard[i][j].sellTower(money);

                    }
                    // cancel
                    if(x>gameBoard[i][j].xC+10 && x<gameBoard[i][j].xC+65 && y<gameBoard[i][j].yC+CONSTANTS::T_SIZE+50 && y>gameBoard[i][j].yC+CONSTANTS::T_SIZE ){
                        towerClicked = false;
                        gameBoard[i][j].isClicked = false;

                    }
                    // upgrade
                    if(x>gameBoard[i][j].xC+55 && x<gameBoard[i][j].xC+105 && y<gameBoard[i][j].yC-CONSTANTS::T_SIZE/2+50 && y>gameBoard[i][j].yC-CONSTANTS::T_SIZE/2){
                        towerClicked = false;
                        gameBoard[i][j].isClicked = false;

                        if(gameBoard[i][j].upgradeCost<=money){
                            money -= gameBoard[i][j].upgradeCost;
                            gameBoard[i][j].upgrade();
                        }
                    }
                }
            }
        }
    }
    else{

        // DETECTS WAVE STARTER icon
    for(size_t i = 0, n = CONSTANTS::B_ROWS; i < n; i++){
        if(gameBoard[i][0].groundID==1){

            if(!waves[wave_num].started&&x<CONSTANTS::T_SIZE&&x>0&&y>i*CONSTANTS::T_SIZE && y < (i+1)*CONSTANTS::T_SIZE ){
                waves[wave_num].start();
            }
        }
    }

    // CLICK ON TOWER TO UPGRADE
    for(size_t i = 0, n = CONSTANTS::B_ROWS; i < n; i++){
               for(size_t j = 0, n = CONSTANTS::B_COLS; j < n; j++){
             if(y>i*CONSTANTS::T_SIZE&&y<(i+1)*CONSTANTS::T_SIZE &&x>(j)*CONSTANTS::T_SIZE&&x<(j+1)*CONSTANTS::T_SIZE && gameBoard[i][j].airID!=-1 && gameBoard[i][j].groundID==0&&!towerClicked) {
                 gameBoard[i][j].isClicked = true;
                 towerClicked = true;
             }
        }
    }
    }
   }
    // PAUSE GAME
    if(x > (CONSTANTS::T_SIZE*11) && x < (CONSTANTS::T_SIZE*11)+50 && y > 8*CONSTANTS::T_SIZE+15 && y < 8*CONSTANTS::T_SIZE+15+50){
            started = false;    
    }

    // IF PAUSED, OPEN MENU
    if(!started){
        //  RESUME
        if(x > 350 && x < 500 && y > 200 && y < 275){
            started = true;
            timer->start();
        }   // QUITS LEVEL, TAKES BACK TO LEVEL PICK
        else if (x > 350 && x < 500 && y > 300 && y < 375){
            emit quitGame();
            this->close();
        }   // RESTART
        else if (x > 350 && x < 500 && y > 400 && y < 475){
                newGame(levelPicked,diff);
        }
    }
    // CHANGE SPEED OF GAME
    if(x > 10*CONSTANTS::T_SIZE && x < 10*CONSTANTS::T_SIZE+50 && y > 8*CONSTANTS::T_SIZE+15 && y < 8*CONSTANTS::T_SIZE+15+50 ){
        changeSpeed();
    }

}

// spawns men over time that are not in game
void GameWindow::spawnMen(){
    waves[wave_num].spawn();
}
// calls each individual men move function
void GameWindow::moveMen(){
    for(int i = 0; i< CONSTANTS::MAX_ENEM; i++){
        if(waves[wave_num].enemies[i].inGame)
        waves[wave_num].enemies[i].move(level_G, level_A, lives);
    }
}

// calls every tiles attack function
void GameWindow::towerPhysics(){
    for(size_t i = 0, n = CONSTANTS::B_ROWS; i < n; i++){
        for(size_t j = 0, n = CONSTANTS::B_COLS; j < n; j++){
          gameBoard[i][j].attack(waves[wave_num].enemies);

        }
    }
}

void GameWindow::checkKills(){
    for(size_t i = 0, n = CONSTANTS::MAX_ENEM; i < n; i ++){
        bool killed = waves[wave_num].enemies[i].checkDeath();
        if(killed){
            if(waves[wave_num].enemies[i].type==1)
            money+=10;
            else if(waves[wave_num].enemies[i].type==2)
              money+=15;
            else if(waves[wave_num].enemies[i].type==3)
              money+=50;
            else if(waves[wave_num].enemies[i].type==4)
              money+=20;
        }
    }
}
// checks to see if user lost
void GameWindow::checkLoss(){
    if(lives <= 0){
        timer->stop();
        userLost = true;
    }
}
// function called when run out of lives.

// stops game loop
void GameWindow::messageUser(){
    if(userLost&&countloss==0){
        countloss =1;
        popUpWindow = new QWidget();
        QLabel *label = new QLabel("You ran out of Lives!!");
        QVBoxLayout *layout = new QVBoxLayout;
        QVBoxLayout *buttonlayout = new QVBoxLayout;
        QPushButton *closebutton = new QPushButton("Exit");
        QPushButton *againbutton = new QPushButton("Play Again");
        QObject::connect(closebutton, SIGNAL(pressed()), this, SLOT(closeGame()));
        QObject::connect(againbutton, SIGNAL(pressed()), this, SLOT(restartGame()));
        layout->addWidget(label);
        buttonlayout->addWidget(closebutton);
        buttonlayout->addWidget(againbutton);
        layout->addLayout(buttonlayout);
        popUpWindow->setLayout(layout);
        popUpWindow->setFixedSize(200,200);
        popUpWindow->show();

    }
}

void GameWindow::userWon(){
    timer->stop();
    popUpWindow = new QWidget();
    QLabel *label = new QLabel("Congratulations!! YOU WON!! ");
    QVBoxLayout *layout = new QVBoxLayout;
    QVBoxLayout *buttonlayout = new QVBoxLayout;
    QPushButton *closebutton = new QPushButton("Exit");
    QPushButton *againbutton = new QPushButton("Play Again");
    QObject::connect(closebutton, SIGNAL(pressed()), this, SLOT(closeGame()));
    QObject::connect(againbutton, SIGNAL(pressed()), this, SLOT(restartGame()));
    layout->addWidget(label);
    buttonlayout->addWidget(closebutton);
    buttonlayout->addWidget(againbutton);
    layout->addLayout(buttonlayout);
    popUpWindow->setLayout(layout);
    popUpWindow->setFixedSize(300,300);
    popUpWindow->show();
}


void GameWindow::closeWindow(){
    popUpWindow->close();
}

void GameWindow::closeGame(){
    popUpWindow->close();
    this->close();
}

void GameWindow::restartGame(){
    this->close();
    emit quitGame();
    popUpWindow->close();

}

void GameWindow::startNewGame(){

    popUpWindow = new QWidget;
    QPushButton *newGameButton = new QPushButton("NEW GAME");
    QPushButton *quitButton = new QPushButton("QUIT");
    QObject::connect(quitButton, SIGNAL(pressed()), this, SLOT(closeGame()));
    QObject::connect(newGameButton, SIGNAL(pressed()), this, SLOT(restartGame()));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(newGameButton);
    layout->addWidget(quitButton);
    popUpWindow->setFixedSize(100,100);


}void GameWindow::startGame(int level, int difficulty){
    newGame(level,difficulty);
}

void GameWindow::setDif1(){
    diff = 1;
    lives = 100;
    money = 500;
}

void GameWindow::setDif2(){
     diff = 2;
     lives = 50;
     money = 250;
}

void GameWindow::setDif3(){
     diff = 3;
     lives = 20;
     money = 100;
}


GameWindow::~GameWindow()
{
    delete ui;
}
