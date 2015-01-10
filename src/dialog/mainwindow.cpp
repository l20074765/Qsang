#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startscene.h"
#include "mywindow.h"
#include "serverdialog.h"
#include "server.h"
#include "client.h"
#include "engine.h"
#include "connectiondialog.h"


#include <QGraphicsView>
#include <QGraphicsItem>
#include <QLabel>
#include <QDebug>
#include <QHBoxLayout>
#include <QDialog>
#include <QMessageBox>
#include <QProcess>


static QRectF rectf(-1280/2,-800/2,1280,800);


class FitView : public QGraphicsView
{
public:
    FitView(QGraphicsScene *scene):QGraphicsView(scene)
    {
        setSceneRect(rectf);
        setRenderHints(QPainter::TextAntialiasing | QPainter::Antialiasing);

    }
protected:
    virtual void resizeEvent(QResizeEvent *event)

    {

        QGraphicsView::resizeEvent(event);
    }
};



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serverDialog = NULL;
    connection_dialog = new ConnectionDialog(this);


    connect(ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->actionAbout,SIGNAL(triggered()),SLOT(actionAbout_triggered()));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->actionStart_game,SIGNAL(triggered()),this,SLOT(actionStart_Game_triggered()));
    connect(ui->actionJoin_game,SIGNAL(triggered()),connection_dialog,SLOT(exec()));

    connect(ui->actionRestart_game,SIGNAL(triggered()),this,SLOT(actionRestart_game_triggered()));

    connect(connection_dialog,SIGNAL(accepted()),this,SLOT(actionRestart_game_triggered()));
    QList<QAction*> actions;
    actions << ui->actionStart_game //Start_Server
            << ui->actionJoin_game
            << ui->actionReplay
            << ui->actionPackage_manager
            << ui->actionConfigure
            << ui->actionGeneral_overview
            << ui->actionCard_overview
            << ui->actionScenario_overview
            << ui->actionAbout
            << ui->actionAbout_Qt;

    StartScene *startScene  = new StartScene;
    foreach(QAction *action,actions)
    {
        startScene->addButton(action);
    }


    scene = startScene;
    view = new FitView(scene);
    setCentralWidget(view);



}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::actionAbout_triggered()
{

    QString content = "<h3>Hello</h3>";
    content.append("<center><img src='image/generals/big/bgm_liubei.png'> <br /> </center>") ;
    content.append("<p><a href='http://www.baidu.com' target='_blank'>http://www.baidu.com</a></p>");

    MyWindow *window = new MyWindow("About Sang",QSize(420, 450));
   // window->setZValue(9.0);
    scene->addItem(window);
    window->setContent(content);
    window->addCloseButton();
    window->moveToCenter();
    window->show();
}


void MainWindow::actionStart_Game_triggered()
{
    qDebug()<<"actionStart_Game_triggered";
    if(serverDialog == NULL)
    {
        serverDialog = new ServerDialog(this);
        if(serverDialog == NULL)  return;//fail
    }
    serverDialog->exec();
    if(serverDialog->result() != QDialog::Accepted)
        return;
    //创建数据库


    Server *server = new Server(this);
    if(!server->listen())
    {
        QMessageBox::warning(this,TR("Warning"),TR("Can not start server!"));
        return;
    }

    if(serverDialog->isPCConsole())
    {
        server->createNewRoom();
        actionRestart_game_triggered();

    }
    ui->actionJoin_game->disconnect();
    //重新开启客户端
    connect(ui->actionJoin_game, SIGNAL(triggered()), this, SLOT(startGameInAnotherInstance()));


    qDebug()<<"actionStart_Game_triggered1";


    StartScene *start_scene = qobject_cast<StartScene *>(scene);
    if(start_scene)
    {
        start_scene->switchToServer(server);

    }

}

void MainWindow::startGameInAnotherInstance(){
    QProcess::startDetached(QApplication::applicationFilePath(), QStringList());
}



void MainWindow::actionRestart_game_triggered()
{
    Client *client = new Client(this);

}
