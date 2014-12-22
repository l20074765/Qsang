#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    ~Server();
};

#endif // SERVER_H
