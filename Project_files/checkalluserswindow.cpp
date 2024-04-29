#include "checkalluserswindow.h"
#include "ui_checkalluserswindow.h"
#include "usersmodel.h"
#include <QAbstractItemView>

checkalluserswindow::checkalluserswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkalluserswindow)
{
    ui->setupUi(this);
    ui->tableViewUsers->setModel(new UsersModel);
    ui->tableViewUsers->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewUsers->verticalHeader()->hide();
    ui->tableViewUsers->setSelectionBehavior(QAbstractItemView::SelectRows);
}

checkalluserswindow::~checkalluserswindow()
{
    delete ui;
}

void checkalluserswindow::on_ButtonBack_clicked()
{
    close();
}


void checkalluserswindow::on_tableViewUsers_doubleClicked(const QModelIndex &index)
{
    const auto mi = index.siblingAtColumn(0);
    int userId = ui->tableViewUsers->model()->data(mi, Qt::UserRole).toInt();
    ChangeUserFromAdmin wn(userId);
    wn.exec();
    ui->tableViewUsers->setModel(new UsersModel);
}

