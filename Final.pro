#-------------------------------------------------
#
# Project created by QtCreator 2014-11-13T19:47:24
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Final
TEMPLATE = app


SOURCES += main.cpp\
    tile.cpp \
    enemy.cpp \
    pictures.cpp \
    circle.cpp \
    gamewindow.cpp \
    needles.cpp \
    projectiles.cpp \
    wave.cpp \
    stages.cpp \
    draw.cpp \
    choosewindow.cpp \
    constants.cpp

HEADERS  += \
    tile.h \
    enemy.h \
    pictures.h \
    circle.h \
    needles.h \
    projectiles.h \
    wave.h \
    stages.h \
    draw.h \
    choosewindow.h \
    gamewindow.h \
    constants.h

FORMS    += mainwindow.ui \
    gamewindow.ui \
    choosewindow.ui
