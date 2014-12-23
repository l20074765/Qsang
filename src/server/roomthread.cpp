#include "roomthread.h"

RoomThread::RoomThread(QObject *parent, const QString &mode)
    :QThread(parent),mode(mode)
{

}

RoomThread::~RoomThread()
{

}

