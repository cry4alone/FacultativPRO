#include "studentfacultativeswindow.h"
#include "ui_studentfacultativeswindow.h"

studentfacultativeswindow::studentfacultativeswindow(QWidget *parent, User user) :
    QDialog(parent),
    ui(new Ui::studentfacultativeswindow)
{
    m_user = user;
    ui->setupUi(this);
    ui->tableView->setModel(new FacultativesModel(nullptr, 0, m_user.ID));
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

void studentfacultativeswindow::on_signFacultativButton_clicked()
{
    signForFacultativWindow sffw(nullptr, m_user.ID);
    sffw.exec();
    ui->tableView->setModel(new FacultativesModel(nullptr, 0, m_user.ID));
}

void studentfacultativeswindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    hide();
    facultativScheduleWindow fsw;
    show();
}

