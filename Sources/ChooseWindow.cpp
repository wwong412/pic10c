#include "choosewindow.h"
#include "ui_choosewindow.h"

ChooseWindow::ChooseWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseWindow)
{
    ui->setupUi(this);
    // main layout for gui
    QVBoxLayout* gui = new QVBoxLayout;
    
    // Title for gui
    QHBoxLayout* title = new QHBoxLayout;
    QLabel * title_label = new QLabel("Welcome to Number Defense!");
    title->addWidget(title_label);
    
    // Creating level select layout for gui
    QVBoxLayout* level_select = new QVBoxLayout;
    QLabel* label = new QLabel("Level Select");
    level_select->addWidget(label);
            // creates three push buttons for different map layouts
    QPushButton* level1 = new QPushButton( "Level 1", 0);
    QPushButton* level2 = new QPushButton( "Level 2", 0);
    QPushButton* level3 = new QPushButton( "Level 3", 0);
            // sets their fixed size
    level1->setFixedSize(125,50);
    level2->setFixedSize(125,50);
    level3->setFixedSize(125,50);
            // add to layout
    level_select->addWidget(level1);
    level_select->addWidget(level2);
    level_select->addWidget(level3);
            // connects pressed push button that determines the maps layout
            // when one of this buttons is pressed, its slot calls the startLevel function
            // which starts the game
    QObject::connect(level1, SIGNAL(pressed()), this, SLOT(pickLevel1()));
    QObject::connect(level2, SIGNAL(pressed()), this, SLOT(pickLevel2()));
    QObject::connect(level3, SIGNAL(pressed()), this, SLOT(pickLevel3())); 
    
    
    // Creating Difficulty select layout for gui
    QVBoxLayout* diff_select = new QVBoxLayout;
    QLabel* dif_label = new QLabel("Difficulty Select");
    diff_select->addWidget(dif_label);
            // creates three radio buttons for difficulty settings, adds them to button group
    QButtonGroup *bgroup = new QButtonGroup;
    QRadioButton* diff1 = new QRadioButton( "Easy", 0);
    QRadioButton* diff2 = new QRadioButton( "Medium", 0);
    QRadioButton* diff3 = new QRadioButton( "Hard", 0);
    bgroup->addButton(diff1);
    bgroup->addButton(diff2);
    bgroup->addButton(diff3);
    diff1->setChecked(true);        // set easy difficulty as checked
            // adds Rbuttons to layout
    diff_select->addWidget(diff1);
    diff_select->addWidget(diff2);
    diff_select->addWidget(diff3);
            // connects pressed radio button to its slot
            // the corresponding slot sets difficulty by changing lives and money
    QObject::connect(diff1, SIGNAL(pressed()), this, SLOT(setDiff1()));
    QObject::connect(diff2, SIGNAL(pressed()), this, SLOT(setDiff2()));
    QObject::connect(diff3, SIGNAL(pressed()), this, SLOT(setDiff3()));
   

    // New horizontal layout to lay level and difficulty side by side
    QHBoxLayout * pick = new QHBoxLayout;
    pick->addLayout(level_select);
    pick->addLayout(diff_select);
   
    // set title to center and add first
    title->setAlignment(Qt::AlignHCenter);
    gui->addLayout(title);
    
    // add pick layout next
    gui->addLayout(pick);
    
    // set this widget's layout and fixed size
    // show on creation
    this->setLayout(gui);
    this->setFixedSize(300,300);
    this->show();

}

ChooseWindow::~ChooseWindow()
{
    delete ui;
}

// slots set difficulty
void ChooseWindow::setDiff1(){
    difficulty = 1;
}

void ChooseWindow::setDiff2(){
    difficulty = 2;
}

void ChooseWindow::setDiff3(){
    difficulty = 3;
}

// slots that change the map layout by picking level
// also emits the signal that starts the game with given inputs
void ChooseWindow::pickLevel1(){
    level = 1;
    isVisible = false;
    emit startgame(level,difficulty);
    this->close();

}
void ChooseWindow::pickLevel2(){
    level = 2;
    isVisible = false;
    emit startgame(level,difficulty);
    this->close();
}
void ChooseWindow::pickLevel3(){
   level = 3;
   isVisible = false;
   emit startgame(level,difficulty);
   this->close();
}
