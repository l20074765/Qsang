#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
private slots:
    void actionAbout_triggered();
    void actionStart_Game_triggered();
};

#endif // MAINWINDOW_H
