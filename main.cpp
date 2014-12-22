#include "mainwindow.h"
#include <QApplication>
#include "audio.h"
#include "engine.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sang = new Engine;

    Audio::init();
    MainWindow w;
    w.show();
    return a.exec();
}
