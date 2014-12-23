#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include <QDialog>
class QLineEdit;
class QGroupBox;
class QButtonGroup;


class ServerDialog : public QDialog
{
    Q_OBJECT
public:
    ServerDialog(QWidget *parent = 0);
    ~ServerDialog();

    bool isPCConsole()const{return this->pc_console;}
private:
    QWidget *createBasicTab();
    QGroupBox *createGameModeBox();
    QLayout *createButtonLayout();


    QLineEdit *server_name_edit;
    //QButtonGroup *mode_group;
    bool pc_console;
private slots:
    void serverButtonClicked();
};

#endif // SERVERDIALOG_H
