#include "studentfacultativeswindow.h"
#include "ui_studentfacultativeswindow.h"

studentfacultativeswindow::studentfacultativeswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentfacultativeswindow)
{
    ui->setupUi(this);
}

studentfacultativeswindow::~studentfacultativeswindow()
{
    delete ui;
}

void studentfacultativeswindow::on_ButtonBack_clicked()
{
    close();
}

