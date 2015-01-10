#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "QGraphicsScene"
#include "button.h"
#include "server.h"
class QAction;
class QTextEdit;

class StartScene : public QGraphicsScene
{
    Q_OBJECT
public:
    StartScene();
    ~StartScene();

    void addButton(QAction *action);
    void switchToServer(Server *server);
private:
    QList<Button *>buttons;
    QTextEdit *server_log;
};

#endif // STARTSCENE_H
