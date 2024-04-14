#include "addnewuserwindow.h"
#include "ui_addnewuserwindow.h"

#include "userdb.h"

AddNewUserWindow::AddNewUserWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddNewUserWindow)
{
    ui->setupUi(this);
}

AddNewUserWindow::~AddNewUserWindow()
{
    delete ui;
}

void AddNewUserWindow::on_pushBtnCancel_clicked()
{
    close();
}


void AddNewUserWindow::on_pushBtnOk_clicked()
{
    //ui->li

    // validate!

    //auto db = UserDb::instance();
    //db.addUser(user);
}

