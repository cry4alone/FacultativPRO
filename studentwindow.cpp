#include "studentwindow.h"
#include "ui_studentwindow.h"

studentwindow::studentwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::studentwindow)
{
    ui->setupUi(this);
}

studentwindow::~studentwindow()
{
    delete ui;
}

void studentwindow::on_changeUserButton_clicked()
{
    emit logout();
}


void studentwindow::on_personalAreaButton_clicked()
{
    studentpersonalwindow spw;
    spw.exec();

}


void studentwindow::on_facultativButton_clicked()
{
    studentfacultativeswindow sfw;
    sfw.exec();
}

