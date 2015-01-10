#-------------------------------------------------
#
# Project created by QtCreator 2014-12-19T16:41:12
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qsang
TEMPLATE = app

CONFIG += warn_on audio



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
    src/server/server.cpp \
    src/server/serversocket.cpp \
    src/server/clientsocket.cpp \
    src/server/roomthread.cpp \
    src/server/serverdialog.cpp \
    src/dialog/connectiondialog.cpp \
    src/client/client.cpp \
    src/core/player.cpp \
    src/client/clientplayer.cpp

HEADERS  += \
    src/dialog/mainwindow.h \
    src/dialog/startscene.h \
    src/dialog/button.h \
    src/core/audio.h \
    src/core/engine.h \
    src/dialog/mywindow.h \
    src/server/server.h \
    src/server/serversocket.h \
    src/server/clientsocket.h \
    src/server/roomthread.h \
    src/server/serverdialog.h \
    src/dialog/connectiondialog.h \
    src/client/client.h \
    src/core/player.h \
    src/client/clientplayer.h

FORMS    += \
    src/dialog/mainwindow.ui \
    src/dialog/connectiondialog.ui


INCLUDEPATH += include
INCLUDEPATH += src/dialog
INCLUDEPATH += src/core
INCLUDEPATH += src/server
INCLUDEPATH += src/client


LIBS += -L.



CONFIG(audio){
    DEFINES += AUDIO_SUPPORT
    INCLUDEPATH += include/fmod
    win32:LIBS += $$PWD/lib/libfmodex.a
}
