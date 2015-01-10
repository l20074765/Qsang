#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <QTcpSocket>
#include <QTcpServer>
class RoomThread;

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    ~Server();
    RoomThread *createNewRoom();
    bool listen();
private:
    QTcpServer *server;
    RoomThread *currentRoom;
    QSet<RoomThread *> rooms;
private slots:
    void processNewConnection();
};

#endif // SERVER_H
