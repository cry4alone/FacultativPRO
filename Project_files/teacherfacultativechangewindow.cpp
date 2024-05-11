#include "teacherfacultativechangewindow.h"
#include "ui_teacherfacultativechangewindow.h"

teacherFacultativeChangeWindow::teacherFacultativeChangeWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::teacherFacultativeChangeWindow)
{
    ui->setupUi(this);
}

teacherFacultativeChangeWindow::~teacherFacultativeChangeWindow()
{
    delete ui;
}

void teacherFacultativeChangeWindow::on_pushButton_clicked()
{
    close();
}

