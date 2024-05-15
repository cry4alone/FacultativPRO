// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "studentpersonalwindow.h"
#include "ui_studentpersonalwindow.h"

studentpersonalwindow::studentpersonalwindow(QWidget *parent, User user) :
    QDialog(parent),
    ui(new Ui::studentpersonalwindow)
{
    m_user = user;
    ui->setupUi(this);
    this->setWindowTitle("Personal Information");
    setWindowIcon(QIcon(":/icon/Icon"));
    showMaximized();
    ui->lineEditpass->setEchoMode(QLineEdit::Normal);
    ui->nameLabel->setText("User ID: " + QString::number(m_user.ID));
    ui->nameEdit->setText(m_user.Name);
    ui->lineEditlogin->setText(m_user.Login);
    ui->lineEditpass->setText(m_user.Password);
    ui->surnameEdit->setText(m_user.Surname);
    ui->groupEdit->setText(m_user.Group);
    ui->groupEdit->setValidator(
         new QRegularExpressionValidator(
             QRegularExpression(R"([A-Z]{2}\d{2}-\d{2}[A-Z]{1})")));
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
    if(login.isEmpty() == true)
    {
        QMessageBox::warning(this,"Ошибка","Login can't be empty!");
        return;
    }
    if(pass.isEmpty() == true)
    {
        QMessageBox::warning(this,"Ошибка","Password can't be empty!");
        return;
    }
    if (name.toInt())
    {
        QMessageBox::warning(this,"Error","Name can't be number!");
        return;
    }
    if (surname.toInt())
    {
        QMessageBox::warning(this,"Error","Surname can't be number!");
        return;
    }
    if (name.isEmpty() || surname.isEmpty())
    {
        QMessageBox::warning(this,"Error","Surname or name can't be empty!");
        return;
    }
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

