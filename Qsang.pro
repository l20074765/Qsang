#-------------------------------------------------
#
# Project created by QtCreator 2014-12-19T16:41:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qsang
TEMPLATE = app

CONFIG += audio



UI_DIR = $$PWD/build/ui
MOC_DIR = $$PWD/build/moc
OBJECTS_DIR = $$PWD/build/obj
DESTDIR = $$PWD/build/bin

SOURCES += main.cpp \
    src/dialog/mainwindow.cpp \
    src/dialog/startscene.cpp \
    src/dialog/button.cpp \
    src/core/audio.cpp \
    src/core/engine.cpp \
    src/dialog/mywindow.cpp \
    src/server/server.cpp

HEADERS  += \
    src/dialog/mainwindow.h \
    src/dialog/startscene.h \
    src/dialog/button.h \
    src/core/audio.h \
    src/core/engine.h \
    src/dialog/mywindow.h \
    src/server/server.h

FORMS    += \
    src/dialog/mainwindow.ui


INCLUDEPATH += include
INCLUDEPATH += src/dialog
INCLUDEPATH += src/core
INCLUDEPATH += src/server

LIBS += -L.



CONFIG(audio){
    DEFINES += AUDIO_SUPPORT
    INCLUDEPATH += include/fmod
    win32:LIBS += $$PWD/lib/libfmodex.a
}
