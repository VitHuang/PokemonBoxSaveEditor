#-------------------------------------------------
#
# Project created by QtCreator 2014-01-04T11:41:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PokemonBoxRSSaveEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    iconbutton.cpp \
    pokemon.cpp \
    miscfunctions.cpp \
    saveblock.cpp \
    boxchangebutton.cpp \
    gbasaveblock.cpp

HEADERS  += mainwindow.h \
    iconbutton.h \
    pokemon.h \
    miscfunctions.h \
    saveblock.h \
    boxchangebutton.h \
    gbasaveblock.h

FORMS    += mainwindow.ui
