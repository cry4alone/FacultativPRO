#include "authwindow.h"
#include "ui_authwindow.h"
#include "mainwindow.h"
#include "regwindow.h"
#include <QMessageBox>
#include <QFile>ъ
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
    bool AuthSuccess = false;
    if(login.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Логин и пароль не могут быть пустыми");
    }
    QFile file("user.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this,"Ошибка","База Данных не открыта");
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QStringList line = in.readLine().split(",");
        if (line[0] == login && line[1] == password)
        {
            MainWindow mw;
            mw.show();
            file.close();
            close();
            AuthSuccess = true;
            break;
        }
    }
    if(AuthSuccess == false)
    {
      QMessageBox::warning(this,"Ошибка","Такой Учетной записи не существует\nпроверьте правильность логина и пароля!");
    }
}

