#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QRadioButton>
#include <QtCore>
#include <QtGui>
#include <QLabel>

namespace Ui {
class ChooseWindow;
}

class ChooseWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseWindow(QWidget *parent = 0);
    ~ChooseWindow();
    
    // level to hold level number
    int level;
    // difficulty number
    int difficulty;

public slots:
    // slots that set difficulty to 1,2,3 respectively from radiobuttons
    void setDiff1();
    void setDiff2();
    void setDiff3();
    // slots that set level to 1,2,3 from radiobuttons
    // these also call the startgame signal which begins the game
    void pickLevel1();
    void pickLevel2();
    void pickLevel3();

signals:
    // signal sent to gamewindow class with level and difficulty
    void startgame(int level, int difficulty);

private:
    Ui::ChooseWindow *ui;
};

#endif // CHOOSEWINDOW_H
