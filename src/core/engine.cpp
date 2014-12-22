#include "engine.h"
#include "audio.h"
#include <QFile>
#include <QtDebug>


Engine *Sang = NULL;


Engine::Engine()
{
    Sang = this;
}

Engine::~Engine()
{
    if(Sang) Sang->deleteLater();
}



void Engine::palyAudio(const QString &name)
{
    QString fileName = QString("%1/%2.ogg").arg("audio/system").arg(name);
  //  qDebug()<<"fileName:"<<QFile::exists(fileName)<<fileName;
    if(QFile::exists(fileName))
        Audio::play(fileName);
}
