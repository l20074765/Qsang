#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>


class ServerSocket : public QObject
{
    Q_OBJECT
public:
    explicit ServerSocket(QObject *parent = 0);
    ~ServerSocket();

signals:

public slots:
};

#endif // SERVERSOCKET_H
