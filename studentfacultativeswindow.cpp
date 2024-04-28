#include "studentfacultativeswindow.h"
#include "ui_studentfacultativeswindow.h"

studentfacultativeswindow::studentfacultativeswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentfacultativeswindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(new FacultativesModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

studentfacultativeswindow::~studentfacultativeswindow()
{
    delete ui;
}

void studentfacultativeswindow::on_ButtonBack_clicked()
{
    close();
}

