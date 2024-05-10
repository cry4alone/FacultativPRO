#include "teacherwindow.h"
#include "ui_teacherwindow.h"
#include "teachercreatefacultative.h"

TeacherWindow::TeacherWindow(QWidget *parent, int UserID)
    : QMainWindow(parent)
    , ui(new Ui::TeacherWindow)
{
    ui->setupUi(this);
    m_UserID = UserID;
    connect(ui->actionChangeUser, &QAction::triggered,
            this, &TeacherWindow::logout);

}

TeacherWindow::~TeacherWindow()
{
    delete ui;
}

void TeacherWindow::on_facultativButton_clicked()
{
    //TODO
}


void TeacherWindow::on_createButton_clicked()
{
    qDebug() << m_UserID;
    teacherCreateFacultative tcf(nullptr, m_UserID);
    hide();
    tcf.exec();
    show();
}

