######################################################################
# Automatically generated by qmake (2.01a) ?? 5? 18 10:49:40 2012
######################################################################
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
#TARGET =
DEPENDPATH += .
INCLUDEPATH += .

unix{
    LIBS += -lbiodaq
}
#INCLUDEPATH +="C:\Advantech\DAQNavi\Driver\USB4716"
#LIBS += "C:\Advantech\DAQNavi\Driver\USB4716\Bio4716"

# Input
HEADERS += configuredialog.h \
           streamingbufferedai.h \
           inc/bdaqctrl.h \
           common/simplegraph.h
FORMS += configuredialog.ui streamingbufferedai.ui
SOURCES += configuredialog.cpp \
           main.cpp \
           streamingbufferedai.cpp \
           common/simplegraph.cpp
RESOURCES += streamingbufferedai.qrc
