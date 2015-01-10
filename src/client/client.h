#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>


class ClientPlayer;


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0,const QString &filename = QString());
    ~Client();

signals:

public slots:
private:
    QTcpSocket *socket;

    QList<const ClientPlayer*> players;
};

#endif // CLIENT_H
