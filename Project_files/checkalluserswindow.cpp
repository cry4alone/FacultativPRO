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
    if(ui->comboBoxMode->currentIndex())
    {
        DeleteUser(userId);
    }
    else
    {
        UpdateUser(userId);
    }
    ui->tableViewUsers->setModel(new UsersModel);
}

void checkalluserswindow::DeleteUser(int UserId)
{
    QMessageBox::StandardButton result = QMessageBox::question(this,"Warning", "This action will delete the user and all associated dependencies. Are you sure you want to proceed?", QMessageBox::Yes|QMessageBox::No);
    //TODO : обработать нажатия кнопок
    if (result == QMessageBox::Yes)
    {
        UserDb::instance().deleteUser(UserId);
        QMessageBox::information(this,"Notification","User was deleted successfully!");
    }
    else
    {
        return;
    }

}

void checkalluserswindow::UpdateUser(int UserId)
{
    ChangeUserFromAdmin wn(UserId);
    wn.exec();
}
