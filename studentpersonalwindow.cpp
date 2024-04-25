#include "studentpersonalwindow.h"
#include "ui_studentpersonalwindow.h"

studentpersonalwindow::studentpersonalwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentpersonalwindow)
{
    ui->setupUi(this);
}

studentpersonalwindow::~studentpersonalwindow()
{
    delete ui;
}

void studentpersonalwindow::on_CancelButton_clicked()
{
    close();
}

