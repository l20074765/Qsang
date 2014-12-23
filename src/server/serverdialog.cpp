#include "serverdialog.h"
#include "engine.h"


#include <QTabWidget>
#include <QLineEdit>
#include <QLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QButtonGroup>
#include <QRadioButton>
#include <QPushButton>



ServerDialog::ServerDialog(QWidget *parent)
    :QDialog(parent)
{
    setWindowTitle(TR("Start server"));
    QTabWidget *tabWidget = new QTabWidget();
    tabWidget->addTab(createBasicTab(),TR("Basic"));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tabWidget);
    layout->addLayout(createButtonLayout());
    setLayout(layout);


    pc_console = false;
}

ServerDialog::~ServerDialog()
{

}



QWidget *ServerDialog::createBasicTab()
{
    server_name_edit = new QLineEdit();
    server_name_edit->setText(TR("QSang"));


    QFormLayout *form_layout = new QFormLayout;


    form_layout->addRow(TR("Server name"),server_name_edit);
    form_layout->addRow(createGameModeBox());

    QWidget *widget = new QWidget();
    widget->setLayout(form_layout);
    return widget;


}


QGroupBox *ServerDialog::createGameModeBox()
{
    QGroupBox *groupBox = new QGroupBox(TR("Game mode"));
    //mode_group = new QButtonGroup;

    //normal mode
    QRadioButton *button = new QRadioButton(TR("3V3"));
    //QGroupBox *box = new QGroupBox(TR("3v3 options"));

   // mode_group->addButton(button);


    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(button);
   // layout->addWidget(box);

    groupBox->setLayout(layout);

    return groupBox;
}



QLayout *ServerDialog::createButtonLayout()
{
    QHBoxLayout *button_layout = new QHBoxLayout;

    QPushButton *server_button = new QPushButton(TR("Start Server"));
    QPushButton *pc_button = new QPushButton(TR("PC Console"));
    QPushButton *cancel_button = new QPushButton(TR("Cancel"));


    connect(server_button, SIGNAL(clicked()), this, SLOT(serverButtonClicked()));
    connect(cancel_button, SIGNAL(clicked()), this, SLOT(reject()));

    button_layout->addWidget(server_button);
    button_layout->addStretch();
    button_layout->addWidget(pc_button);
    button_layout->addWidget(cancel_button);

    return button_layout;

}




void ServerDialog::serverButtonClicked()
{
    accept();
}
