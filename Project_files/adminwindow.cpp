// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "adminwindow.h"
#include "ui_adminwindow.h"

#include "addnewuserwindow.h"
#include "checkalluserswindow.h"

AdminWindow::AdminWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    setWindowIcon(QIcon(":/icon/Icon"));
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_pushButton_clicked()
{
    emit logout();
}


void AdminWindow::on_pushBtnNewUser_clicked()
{
    hide();

    AddNewUserWindow w;
    w.exec();
    show();
}


void AdminWindow::on_pushBtnAllUsers_clicked()
{
    hide();
    checkalluserswindow w;
    w.exec();
    show();
}



