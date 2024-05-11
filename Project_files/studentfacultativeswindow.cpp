#include "studentfacultativeswindow.h"
#include "ui_studentfacultativeswindow.h"

studentfacultativeswindow::studentfacultativeswindow(QWidget *parent, User user) :
    QDialog(parent),
    ui(new Ui::studentfacultativeswindow)
{
    m_user = user;
    ui->setupUi(this);
    fac_mod = new FacultativesModel(nullptr, 0,m_user.ID);
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

    fac_mod = new FacultativesModel(nullptr, 0, m_user.ID);
    ui->tableView->setModel(fac_mod);
}

void studentfacultativeswindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    int FacID = ui->tableView->model()->data(index, Qt::UserRole).toInt();
    Facultativ m_Fac = UserDb::instance().getFacultativByID(FacID);
    facultativScheduleWindow fsw(nullptr, m_Fac, m_user.ID);
    fac_mod = new FacultativesModel(nullptr, 0, m_user.ID);
    ui->tableView->setModel(fac_mod);
    //fsw->reset(new facultativScheduleWindow(this , m_Fac, m_user.ID));
    fsw.exec();
}

