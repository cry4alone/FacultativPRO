// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "addnewuserwindow.h"
#include "ui_addnewuserwindow.h"

#include "userdb.h"

AddNewUserWindow::AddNewUserWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddNewUserWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    this->setWindowTitle("Add User");
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
    QString rpass = ui->lineEditrepeatpass->text();
    QString Name = ui->nameEdit->text();
    QString Surname = ui->surnameEdit->text();
    int index = ui->comboBox->currentIndex();
    if (login.trimmed().isEmpty())
    {
        QMessageBox::warning(this,"Error","Login can't be empty!");
        return;
    }
    if(pass.isEmpty() == true)
    {
        QMessageBox::warning(this,"Error","Password can't be empty!");
        return;
    }
    if(pass != rpass)
    {
        QMessageBox::warning(this,"Error","Passwords aren't the same!");
        return;
    }
    auto& db = UserDb::instance();
    User* currUser = nullptr;
    if (index == 0)
    {
        if (isNumber(Name))
        {
            QMessageBox::warning(this,"Error","Name can't be number!");
            return;
        }
        if (isNumber(Surname))
        {
            QMessageBox::warning(this,"Error","Surname can't be number!");
            return;
        }
        if (Name.isEmpty() || Surname.isEmpty())
        {
            QMessageBox::warning(this,"Error","Surname or name can't be empty!");
            return;
        }
        User::Role role = User::Role::Teacher;
        currUser = new User(login, pass, role, Name, Surname, NULL);
    }
    else
    {
        User::Role role = User::Role::Administrator;
        currUser = new User(login, pass, role, NULL, NULL, NULL);
    }
    db.addUser(*currUser);
    QMessageBox::information(this,"Notification","New user was successfully created!");
    delete currUser;
    close();
}

bool AddNewUserWindow::isNumber(QString &str)
{
    bool ok;
    int num = str.toInt(&ok);
    return ok;
}


