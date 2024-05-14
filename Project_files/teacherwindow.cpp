// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "teacherwindow.h"
#include "ui_teacherwindow.h"
#include "teachercreatefacultative.h"

TeacherWindow::TeacherWindow(QWidget *parent, int UserID)
    : QMainWindow(parent)
    , ui(new Ui::TeacherWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    setWindowIcon(QIcon(":/icon/Icon"));
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
    teacherFacultativesWindow tfw(nullptr, m_UserID);
    hide();
    tfw.exec();
    show();
}


void TeacherWindow::on_createButton_clicked()
{
    teacherCreateFacultative tcf(nullptr, m_UserID);
    hide();
    tcf.exec();
    show();
}

