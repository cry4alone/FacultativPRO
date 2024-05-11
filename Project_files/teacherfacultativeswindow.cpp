#include "teacherfacultativeswindow.h"
#include "ui_teacherfacultativeswindow.h"

teacherFacultativesWindow::teacherFacultativesWindow(QWidget *parent, int UserID)
    : QDialog(parent)
    , ui(new Ui::teacherFacultativesWindow)
{
    ui->setupUi(this);
    qDebug() << UserID;
    FacultativesModel *FacMod = new FacultativesModel(nullptr, 3, UserID);
    FacMod->setTeacherFacultatives(UserID);
    ui->tableView->setModel(FacMod);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

teacherFacultativesWindow::~teacherFacultativesWindow()
{
    delete ui;
}

void teacherFacultativesWindow::on_pushButton_clicked()
{
    close();
}


void teacherFacultativesWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    teacherFacultativeChangeWindow tfcw;
    tfcw.exec();
}

