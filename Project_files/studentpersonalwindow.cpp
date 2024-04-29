#include "studentpersonalwindow.h"
#include "ui_studentpersonalwindow.h"

studentpersonalwindow::studentpersonalwindow(QWidget *parent, User user) :
    QDialog(parent),
    ui(new Ui::studentpersonalwindow)
{
    m_user = user;
    qDebug() << m_user.ID;
    ui->setupUi(this);
    ui->lineEditpass->setEchoMode(QLineEdit::Normal);
    ui->nameLabel->setText("User ID: " + QString::number(m_user.ID));
    ui->nameEdit->setText(m_user.Name);
    ui->lineEditlogin->setText(m_user.Login);
    ui->lineEditpass->setText(m_user.Password);
    ui->surnameEdit->setText(m_user.Surname);
    ui->groupEdit->setText(m_user.Group);
}

studentpersonalwindow::~studentpersonalwindow()
{
    delete ui;
}

void studentpersonalwindow::on_CancelButton_clicked()
{
    close();
}


void studentpersonalwindow::on_ChangeButton_clicked()
{
    const auto login = ui->lineEditlogin->text();
    const auto pass = ui->lineEditpass->text();
    const auto name = ui->nameEdit->text();
    const auto surname = ui->surnameEdit->text();
    const auto group = ui->groupEdit->text();
    m_user.Login = login;
    m_user.Password = pass;
    m_user.Name = name;
    m_user.Surname = surname;
    m_user.Group = group;
    bool success = UserDb::instance().changeUser(m_user);
    if (success)
    {
        QMessageBox::information(this, "Notifiction","Successful change");
    }
    else
    {
        QMessageBox::warning(this,"Error","Unsuccessful change");
    }
    close();
}

