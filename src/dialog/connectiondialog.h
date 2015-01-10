#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionDialog(QWidget *parent = 0);
    ~ConnectionDialog();

private slots:
    void on_pushButton_detect_clicked();

    void on_pushButton_connect_clicked();

private:
    Ui::ConnectionDialog *ui;
};

#endif // CONNECTIONDIALOG_H
