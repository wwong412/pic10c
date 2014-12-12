#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QPen>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QDebug>
#include <QColor>
#include <QtCore>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSize>

#include "draw.h"
#include "math.h"
#include "tile.h"
#include "pictures.h"
#include "enemy.h"
#include "wave.h"
#include "projectiles.h"
#include "constants.h"

namespace GAME_CONST{

const int START_MON1 = 500;
const int START_MON2 = 400;
const int START_MON3 = 300;

const int START_LIVES1 = 50;
const int START_LIVES2 = 25;
const int START_LIVES3 = 10;

const int TOWER1COST = 50;
const int TOWER2COST = 150;
const int TOWER3COST = 100;
const int TOWER4COST = 200;

}

// Main class for game logic

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    // initilizes beginning values
    void loadLevel();
    void newGame();
    void newGame(int level, int difficulty);
    //
    void towerPhysics();
    void checkWave();
    void checkLoss();
    void checkKills();
    void messageUser();
    void userWon();

    void startNewGame();

    void spawnMen();
    void moveMen();
    void changeSpeed();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);

    void setDif1();
    void setDif2();
    void setDif3();

    void setL1();
    void setL2();
    void setL3();

    int levelPicked;
    bool started;

    int speedChange;

    bool gameStart;

    ~GameWindow();

public slots:
    void redraw();
    void closeWindow();
    void closeGame();
    void restartGame();
    void startGame(int level, int difficulty);

signals:
    void quitGame();

private:
    Ui::GameWindow *ui;
    Draw draw;                      // draw class

    QWidget* popUpWindow;           // messages user lost

    QTimer *timer ;                 // timer for game
    QPainter *myPaint;

    bool loaded;                    // true if loaded once
    bool towerClicked;              // bools for selecting towers
    bool towerPick;
    Pictures p;                     // pictures class

    Wave waves[20];                 // 20 arrays
    int wave_num;

    Tile gameBoard[8][12];
    Enemy wave [50];
    int level_G[8][12];
    int level_A[8][12];
    int money;
    int lives;
    bool userLost;
    int countloss;

    int diff;
    bool tower1clicked;
    bool tower2clicked;
    bool tower3clicked;
    bool tower4clicked;

    int mouseX;
    int mouseY;

};

#endif // GAMEWINDOW_H
