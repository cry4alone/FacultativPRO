#include "facultativschedulewindow.h"
#include "ui_facultativschedulewindow.h"

facultativScheduleWindow::facultativScheduleWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::facultativScheduleWindow)
{
    ui->setupUi(this);
}

facultativScheduleWindow::~facultativScheduleWindow()
{
    delete ui;
}
