#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Qsang");

    this->setCentralWidget(new QLabel("hello!"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
