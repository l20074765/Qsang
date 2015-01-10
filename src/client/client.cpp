#include "client.h"
#include "engine.h"
#include "clientplayer.h"

Client::Client(QObject *parent,const QString &filename) : QObject(parent)
{
    ClientPlayer *player = new ClientPlayer(this);
    players << player;


    socket = new QTcpSocket(this);
    socket->connectToHost(IP_ADDRESS,IP_PORT);
    qDebug()<<"QTcpSocket"<<"socket="<<socket;
}

Client::~Client()
{

}

