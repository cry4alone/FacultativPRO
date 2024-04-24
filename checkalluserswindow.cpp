#include "checkalluserswindow.h"
#include "ui_checkalluserswindow.h"
#include "usersmodel.h"

checkalluserswindow::checkalluserswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkalluserswindow)
{
    ui->setupUi(this);
    ui->tableViewUsers->setModel(new UsersModel);
}

checkalluserswindow::~checkalluserswindow()
{
    delete ui;
}

void checkalluserswindow::on_ButtonBack_clicked()
{
    close();
}

