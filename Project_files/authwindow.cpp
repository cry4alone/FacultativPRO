// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
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
    this->setWindowTitle("Authentification");
    setWindowIcon(QIcon(":/icon/Icon"));
    setFixedSize(400, 350);
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

    QPair<QString, int> result = UserDb::instance().AuthCheck(login, password);
    if (result.first == "0") {
        emit userEntered(User::Administrator, -1);
        return;
    }
    else if (result.first == "1") {
        emit userEntered(User::Teacher, result.second);
        return;
    }
    else if (result.first == "2") {
        emit userEntered(User::Student, result.second);
        return;
    }
    else if (result.first == "None") {
        QMessageBox::warning(
            this, "Ошибка", "Неправильный логин или пароль!");
    }

}


void AuthWindow::on_RegistrationButton_clicked()
{
    RegWindow rw;
    rw.exec();
}

