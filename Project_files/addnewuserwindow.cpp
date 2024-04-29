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
    QString login = ui->lineEditlogin->text();
    QString pass = ui->lineEditpass->text();
    QString Name = ui->nameEdit->text();
    QString Surname = ui->surnameEdit->text();
    int index = ui->comboBox->currentIndex();
    auto& db = UserDb::instance();
    User* currUser = nullptr;
    if (index == 0)
    {
        User::Role role = User::Role::Teacher;
        currUser = new User(login, pass, role, Name, Surname, NULL);
    }
    else
    {
        User::Role role = User::Role::Administrator;
        currUser = new User(login, pass, role, NULL, NULL, NULL);
    }
    db.addUser(*currUser);
    QMessageBox::information(this,"Уведомление","Учетная запись успешно создана!");
    delete currUser;
    close();
}

