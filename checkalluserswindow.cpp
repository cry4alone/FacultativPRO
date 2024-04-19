#include "checkalluserswindow.h"
#include "ui_checkalluserswindow.h"

checkalluserswindow::checkalluserswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkalluserswindow)
{
    ui->setupUi(this);
}

checkalluserswindow::~checkalluserswindow()
{
    delete ui;
}

void checkalluserswindow::on_ButtonBack_clicked()
{
    close();
}

