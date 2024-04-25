#include "regwindow.h"
#include "ui_regwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

RegWindow::RegWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegWindow)
{
    ui->setupUi(this);
    ui->groupEdit->setValidator(
         new QRegularExpressionValidator(
             QRegularExpression(R"([A-Z]{2}\d{2}-\d{2}[A-Z]{1})")));
}

RegWindow::~RegWindow()
{
    delete ui;
}



void RegWindow::on_OkButton_clicked()
{
    const auto login = ui->lineEditlogin->text();
    if (login.trimmed().isEmpty())
    {
        QMessageBox::warning(this,"Error","Login can't be empty!");
        return;
    }
    const auto pass = ui->lineEditpass->text();
    const auto rppass = ui->lineEditrepeatpass->text();
    const auto name = ui->nameEdit->text();
    const auto surname = ui->surnameEdit->text();
    const auto group = ui->groupEdit->text();
    if(pass.isEmpty() == true)
    {
        QMessageBox::warning(this,"Ошибка","Password can't be empty!");
        return;
    }
    if (pass != rppass)
    {
        QMessageBox::warning(this,"Ошибка","Passwords aren't the same!");
        return;
    }
    User* currUser = new User(login, pass, User::Role::Student, name, surname, group);
    UserDb::instance().addUser(*currUser);
    QMessageBox::information(this,"Notification","Personal account was successfully created!");
    delete currUser;
    close();
}


void RegWindow::on_CancelButton_clicked()
{
    close();
}

