#include "server.h"

Server::Server(QObject *parent)
    :QObject(parent)
{
    server = new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(processNewConnection()));
}

Server::~Server()
{

}



void Server::processNewConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();
}
