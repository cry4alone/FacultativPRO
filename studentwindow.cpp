#include "studentwindow.h"
#include "ui_studentwindow.h"

studentwindow::studentwindow(QWidget *parent, int UserID) :
    QMainWindow(parent),
    ui(new Ui::studentwindow)
{
    ui->setupUi(this);
    m_User = UserDb::instance().getUserByID(UserID);
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
    studentpersonalwindow spw(nullptr, m_User);
    spw.exec();

}


void studentwindow::on_facultativButton_clicked()
{
    hide();
    studentfacultativeswindow sfw;
    sfw.exec();
    show();
}

