#include "changeuserfromadmin.h"
#include "ui_changeuserfromadmin.h"

ChangeUserFromAdmin::ChangeUserFromAdmin(int UserID ,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeUserFromAdmin)
{
    ui->setupUi(this);
    this->setWindowTitle("Change User");
    setWindowIcon(QIcon(":/icon/Icon"));
    m_userID = UserID;
    user = UserDb::instance().getUserByID(m_userID);

    if (user.role == User::Role::Administrator)
    {
        ui->tabWidget->widget(1)->hide();
    }
    else if (user.role == User::Role::Teacher)
    {
        ui->UserID_2->setText("User ID: " + QString::number(m_userID));
        ui->lineEditgroup->hide();
        ui->lineEditName->setText(user.Name);
        ui->lineEditSurname->setText(user.Surname);
    }
    else
    {
        ui->UserID_2->setText("User ID: " + QString::number(m_userID));
        ui->lineEditName->setText(user.Name);
        ui->lineEditSurname->setText(user.Surname);
        ui->lineEditgroup->setText(user.Group);
    }
    ui->UserID->setText("User ID: " + QString::number(m_userID));
    ui->lineEditlogin->setText(user.Login);
    ui->lineEditpass->setText(user.Password);
}

ChangeUserFromAdmin::~ChangeUserFromAdmin()
{
    delete ui;
}

void ChangeUserFromAdmin::on_changeButton_clicked()
{
    const auto login = ui->lineEditlogin->text();
    const auto pass = ui->lineEditpass->text();
    const auto name = ui->lineEditName->text();
    const auto surname = ui->lineEditSurname->text();
    const auto group = ui->lineEditgroup->text();
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
    user.Login = login;
    user.Password = pass;
    user.Name = name;
    user.Surname = surname;
    user.Group = group;
    bool success = UserDb::instance().changeUser(user);
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


void ChangeUserFromAdmin::on_cancelButton_clicked()
{
    close();
}

