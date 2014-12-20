#-------------------------------------------------
#
# Project created by QtCreator 2014-12-19T16:41:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qsang
TEMPLATE = app


SOURCES += main.cpp \
    src/dialog/mainwindow.cpp \
    src/dialog/startscene.cpp \
    src/dialog/button.cpp

HEADERS  += \
    src/dialog/mainwindow.h \
    src/dialog/startscene.h \
    src/dialog/button.h

FORMS    += \
    src/dialog/mainwindow.ui



INCLUDEPATH += src/dialog
