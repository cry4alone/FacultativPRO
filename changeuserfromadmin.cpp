#include "changeuserfromadmin.h"
#include "ui_changeuserfromadmin.h"

ChangeUserFromAdmin::ChangeUserFromAdmin(int UserID ,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeUserFromAdmin)
{
    ui->setupUi(this);
    m_userID = UserID;
    qDebug() << "Я ТУТ" <<UserID;
    user = UserDb::instance().getUserByID(m_userID);

    ui->UserID->setText("User ID: " + QString::number(m_userID));
    ui->UserID_2->setText("User ID: " + QString::number(m_userID));
    ui->lineEditlogin->setText(user.Login);
    ui->lineEditpass->setText(user.Password);

    if (user.role == User::Role::Administrator)
    {
        ui->tabWidget->widget(1)->setVisible(false);
    }
    else if (user.role == User::Role::Teacher)
    {
        ui->lineEditgroup->setVisible(false);
        ui->lineEditName->setText(user.Name);
        ui->lineEditSurname->setText(user.Surname);
    }
    else
    {
        ui->lineEditName->setText(user.Name);
        ui->lineEditSurname->setText(user.Surname);
        ui->lineEditgroup->setText(user.Group);
    }

}

ChangeUserFromAdmin::~ChangeUserFromAdmin()
{
    delete ui;
}

void ChangeUserFromAdmin::on_pushButton_2_clicked()
{
    close();
}


void ChangeUserFromAdmin::on_pushButton_clicked()
{

}

