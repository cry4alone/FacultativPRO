// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "teacherfacultativeswindow.h"
#include "ui_teacherfacultativeswindow.h"

teacherFacultativesWindow::teacherFacultativesWindow(QWidget *parent, int UserID)
    : QDialog(parent)
    , ui(new Ui::teacherFacultativesWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Facultatives");
    showMaximized();
    setWindowIcon(QIcon(":/icon/Icon"));
    FacMod = new FacultativesModel(nullptr, UserID);
    FacMod->setTeacherFacultatives(UserID);
    ui->tableView->setModel(FacMod);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

teacherFacultativesWindow::~teacherFacultativesWindow()
{
    delete FacMod;
    delete ui;
}

void teacherFacultativesWindow::on_pushButton_clicked()
{
    close();
}


void teacherFacultativesWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    const auto mi = index.siblingAtColumn(0);
    int FacID = FacMod->data(mi,Qt::UserRole).toInt();
    teacherFacultativeChangeWindow tfcw(nullptr, FacID);
    tfcw.exec();
}

