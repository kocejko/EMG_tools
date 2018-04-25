#-------------------------------------------------
#
# Project created by QtCreator 2017-05-19T12:07:45
#
#-------------------------------------------------

QT       += core gui bluetooth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Bluetooth_echair
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

