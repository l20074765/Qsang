#include "startscene.h"

#include <QAction>
StartScene::StartScene()
{
    setBackgroundBrush(Qt::gray);
}

StartScene::~StartScene()
{

}



void StartScene::addButton(QAction *action)
{
    QString text = action->text();
    Button *button = new Button(text);
    connect(button,SIGNAL(clicked()),action,SLOT(trigger()));
    addItem(button);
    QRectF rect = button->boundingRect();
    int n = buttons.length();
    if(n < 5)
        button->setPos(- rect.width() - 5, (n - 1) * (rect.height() * 1.2));
    else
        button->setPos(5, (n - 6) * (rect.height() * 1.2));

    buttons<<button;
}
