// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "studentfacultativeswindow.h"
#include "ui_studentfacultativeswindow.h"

studentfacultativeswindow::studentfacultativeswindow(QWidget *parent, User user) :
    QDialog(parent),
    ui(new Ui::studentfacultativeswindow)
{
    m_user = user;
    ui->setupUi(this);
    this->setWindowTitle("Facultatives");
    setWindowIcon(QIcon(":/icon/Icon"));
    fac_mod = new FacultativesModel(nullptr, m_user.ID);
    fac_mod->setIdFacultatives(m_user.ID);
    ui->tableView->setModel(fac_mod);
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

    fac_mod->setIdFacultatives(m_user.ID);
    ui->tableView->setModel(fac_mod);
}

void studentfacultativeswindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    const auto mi = index.siblingAtColumn(0);
    int FacID = ui->tableView->model()->data(mi, Qt::UserRole).toInt();
    Facultativ m_Fac = UserDb::instance().getFacultativByID(FacID);
    facultativScheduleWindow fsw(nullptr, m_Fac, m_user.ID);
    fac_mod->setIdFacultatives(m_user.ID);
    ui->tableView->setModel(fac_mod);
    fsw.exec();
}

