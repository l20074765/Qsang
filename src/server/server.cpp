#include "server.h"

Server::Server(QObject *parent)
    :QObject(parent)
{
    server = new QTcpServer(this);
    //connect(server,SIGNAL(newConnection());
}

Server::~Server()
{

}

