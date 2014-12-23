#ifndef ROOMTHREAD_H
#define ROOMTHREAD_H

#include <QThread>
class RoomThread : public QThread
{
    Q_OBJECT
public:
    explicit RoomThread(QObject *parent, const QString &mode);
    ~RoomThread();
private:
    QString mode;
};

#endif // ROOMTHREAD_H
