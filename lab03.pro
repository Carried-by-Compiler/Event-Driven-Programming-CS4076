#-------------------------------------------------
#
# Project created by QtCreator 2018-02-19T09:16:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab03
TEMPLATE = app 

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Character.cpp \
    Command.cpp \
    CommandWords.cpp \
    item.cpp \
    Parser.cpp \
    Room.cpp \
    ZorkUL.cpp \
    #Sources/Character.cpp \
    #Sources/Command.cpp \
    #Sources/CommandWords.cpp \
    #Sources/item.cpp \
    #Sources/main.cpp \
   # Sources/mainwindow.cpp \
    #Sources/Parser.cpp \
    #Sources/Room.cpp \
    #Sources/ZorkUL.cpp
    floor.cpp \
    notes.cpp

HEADERS += \
        mainwindow.h \
    Character.h \
    Command.h \
    CommandWords.h \
    item.h \
    Parser.h \
    Room.h \
    ZorkUL.h \
    floor.h \
    notes.h
    #Headers/Character.h \
    #Headers/Command.h \
    #Headers/CommandWords.h \
    #Headers/item.h \
    #Headers/mainwindow.h \
    #Headers/Parser.h \
    #Headers/Room.h \
    #Headers/ZorkUL.h

FORMS += \
        mainwindow.ui \
    #Forms/mainwindow.ui

RESOURCES += \
    project_images/myresmaps.qrc\
    project_images/roomviews.qrc\
    project_images/itemRes.qrc\
