#include "teacherwindow.h"
#include "ui_teacherwindow.h"

TeacherWindow::TeacherWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TeacherWindow)
{
    ui->setupUi(this);

    connect(ui->actionChangeUser, &QAction::triggered,
            this, &TeacherWindow::logout);

}

TeacherWindow::~TeacherWindow()
{
    delete ui;
}
