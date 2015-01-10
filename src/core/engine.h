#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>

#define TR  tr


#define IP_ADDRESS "127.0.0.1"
#define IP_PORT     10001

class Engine : public QObject
{
    Q_OBJECT
public:
    explicit Engine();
    ~Engine();
    void palyAudio(const QString &name);
signals:

public slots:
};


extern Engine *Sang;


#endif // ENGINE_H
