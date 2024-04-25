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
    User::Role role = static_cast<User::Role>(index);
    auto& db = UserDb::instance();
    User* currUser = nullptr;
    if (index == 0)
    {
        //currUser = new TeacherUser(login, pass, Name, Surname, role);
    }
    else
    {
        //currUser = new AdminUser(login, pass, role);
    }
    db.addUser(*currUser);
    QMessageBox::information(this,"Уведомление","Учетная запись успешно создана!");
    delete currUser;
    close();
}

