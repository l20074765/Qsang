#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startscene.h"


#include <QGraphicsView>
#include <QGraphicsItem>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //scene = NULL;
    connect(ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    QList<QAction*> actions;
    actions << ui->actionStart_game //Start_Server
            << ui->actionJoin_game
            << ui->actionReplay
            << ui->action_Pause
            << ui->actionConfigure
            << ui->actionGeneral_overview
            << ui->actionCard_overview
            << ui->actionScenario_overview
            << ui->actionAbout
            << ui->actionAbout_Qt;

    //StartScene *startScene  = new StartScene;
    startScene  = new StartScene;
    foreach(QAction *action,actions)
    {
        startScene->addButton(action);
    }

    //scene = startScene;
    view = new QGraphicsView();
   view->setScene(startScene);

   setCentralWidget(view);



}

MainWindow::~MainWindow()
{
    delete ui;
}
