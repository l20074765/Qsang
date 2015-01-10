#include "server.h"
#include "roomthread.h"
#include "engine.h"

#include <QtDebug>
Server::Server(QObject *parent)
    :QObject(parent)
{
    server = new QTcpServer(this);
    createNewRoom();
    connect(server,SIGNAL(newConnection()),this,SLOT(processNewConnection()));

    currentRoom = NULL;
}

Server::~Server()
{

}



void Server::processNewConnection()
{

    QTcpSocket *socket = server->nextPendingConnection();

    qDebug()<<"processNewConnection"<<"socket="<<socket;

}



RoomThread *Server::createNewRoom()
{
    RoomThread *newRoom = new RoomThread(this,"3v3");
    currentRoom = newRoom;
    rooms.insert(currentRoom);
    return currentRoom;

}


bool Server::listen()
{
    return server->listen(QHostAddress::Any,IP_PORT);
}
