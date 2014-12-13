
#include "gamewindow.h"
#include "choosewindow.h"
#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow* w = new GameWindow;
    ChooseWindow* choose = new ChooseWindow;
    QObject::connect(choose, SIGNAL(startgame(int,int)), w, SLOT(startGame(int,int)));
    QObject::connect(w, SIGNAL(quitGame()), choose, SLOT(show()));
    return a.exec();
}
