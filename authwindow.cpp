#include "authwindow.h"
#include "ui_authwindow.h"
#include "mainwindow.h"
#include "regwindow.h"
#include "userdb.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>

#include <QRegularExpression>
#include <QRegularExpressionValidator>

AuthWindow::AuthWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthWindow)
{
    ui->setupUi(this);

    // ui->lineEdit->setValidator(
    //     new QRegularExpressionValidator(
    //         QRegularExpression(R"([A-Za-z]{25})"))); // TODO: нижняя граница!

    // ui->lineEdit->setValidator(
    //     new QRegularExpressionValidator(
    //         QRegularExpression(R"([А-Я]{2}-\d{2})"))); // TODO: нижняя граница!
}

AuthWindow::~AuthWindow()
{
    delete ui;
}

void AuthWindow::on_LoginButton_clicked()
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

    QString UserRole = UserDb::instance().AuthCheck(login, password);
    if (UserRole == "Administrator") {
        emit userEntered(User::Administrator);
        return;
    }
    else if (UserRole == "Teacher") {
        emit userEntered(User::Teacher);
        return;
    }
    else if (UserRole == "Student") {
        emit userEntered(User::Student);
        return;
    }
    else if (UserRole == "None") {
        QMessageBox::warning(
            this, "Ошибка", "Неправильный логин или пароль!");
    }

}


void AuthWindow::on_RegistrationButton_clicked()
{
    RegWindow rw;
    rw.exec();
}

