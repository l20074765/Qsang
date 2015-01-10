#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ConnectionDialog;



namespace Ui {
class MainWindow;
}


class QGraphicsScene;
class QGraphicsView;
class StartScene;
class ServerDialog;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView   *view;
    ServerDialog *serverDialog;
    ConnectionDialog   *connection_dialog;
private slots:
    void actionAbout_triggered();
    void actionStart_Game_triggered();
    void startGameInAnotherInstance();
    void actionRestart_game_triggered();
};

#endif // MAINWINDOW_H
