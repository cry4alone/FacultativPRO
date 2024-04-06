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
}

RegWindow::~RegWindow()
{
    delete ui;
}

void RegWindow::on_pushButton_2_clicked()
{
    close();
}


void RegWindow::on_pushButton_clicked()
{
    const auto login = ui->lineEditlogin->text();
    if (login.trimmed().isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Логин пуст");
        return;
    }
    const auto pass = ui->lineEditpass->text();
    const auto rppass = ui->lineEditrepeatpass->text();
    if(pass.isEmpty() == true)
    {
        QMessageBox::warning(this,"Ошибка","Пароли не может быть пустой");
        return;
    }
    if (pass != rppass)
    {
        QMessageBox::warning(this,"Ошибка","Пароли не совпадают");
        return;
    }
    //работа с бд
    QFile f("user.csv");
    f.open(QFile::Append);
    QTextStream ts(&f);
    ts << login << "," << pass <<"\n";
    QMessageBox::information(this,"Уведомление","Учетная запись успешно создана!");
    close();
}

