#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}


class QGraphicsScene;
class QGraphicsView;
class StartScene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    StartScene *startScene;
    QGraphicsView   *view;
};

#endif // MAINWINDOW_H
