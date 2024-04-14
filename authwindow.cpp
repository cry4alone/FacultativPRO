#include "authwindow.h"
#include "ui_authwindow.h"
#include "mainwindow.h"
#include "regwindow.h"
#include "userdb.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>

AuthWindow::AuthWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthWindow)
{
    ui->setupUi(this);
}

AuthWindow::~AuthWindow()
{
    delete ui;
}

void AuthWindow::on_pushButton_clicked()
{
    RegWindow rw;
    rw.exec();
}


void AuthWindow::on_pushButton_2_clicked()
{
    const auto login = ui->lineEdit->text();
    const auto password = ui->lineEdit_2->text();
    if(login.isEmpty() ||
        password.isEmpty())
    {
        QMessageBox::warning(
            this, "Ошибка", "Логин и пароль не могут быть пустыми");
        return;
    }

    // auto db = UserDb::instance();
    // const User user = db.getUserByLoginAndPass(login, password);

    // if (user.role == User::admin) {

    // }


    if (login == "Admin") {
        emit userEntered(User::admin);
        return;
    }
    if (login == "Teacher") {
        emit userEntered(User::teacher);
        return;
    }



}

