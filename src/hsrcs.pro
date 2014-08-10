#-------------------------------------------------
#
# Project created by QtCreator 2014-04-30T12:09:41
#
#-------------------------------------------------

QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hsrcs
TEMPLATE = app

CONFIG += debug_and_release

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    data.qrc
