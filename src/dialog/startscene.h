#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "QGraphicsScene"
#include "button.h"
class QAction;


class StartScene : public QGraphicsScene
{
    Q_OBJECT
public:
    StartScene();
    ~StartScene();

    void addButton(QAction *action);

private:
    QList<Button *>buttons;
};

#endif // STARTSCENE_H
