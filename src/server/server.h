#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QTcpSocket>
#include <QTcpServer>


class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    ~Server();
private:
    QTcpServer *server;
};

#endif // SERVER_H
