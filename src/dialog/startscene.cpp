#include "startscene.h"

#include <QAction>
#include <QTextEdit>
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


void StartScene::switchToServer(Server *server)
{
    foreach(Button *button,buttons)
        delete button;
    buttons.clear();

    server_log = new QTextEdit();
    server_log->setReadOnly(true);
    server_log->resize(700,400);
    server_log->move(-400, -180);
    server_log->setFrameShape(QFrame::NoFrame);
    server_log->setProperty("type", "border");
    QPalette palette;
    palette.setBrush(QPalette::Base, backgroundBrush());
    server_log->setPalette(palette);

    addWidget(server_log);

    server_log->setText("sadfadfafdafdaf\n");
    update();

}


