#include "checkalluserswindow.h"
#include "ui_checkalluserswindow.h"
#include "usersmodel.h"
#include <QAbstractItemView>

checkalluserswindow::checkalluserswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkalluserswindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Administration");
    setWindowIcon(QIcon(":/icon/Icon"));
    m_usersModel = new UsersModel;
    m_usersModel->getOnlyRole(4);
    ui->tableViewUsers->setModel(m_usersModel);
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

void checkalluserswindow::on_comboBoxRole_currentIndexChanged(int index)
{
    m_usersModel->getOnlyRole(index);
    ui->tableViewUsers->setModel(m_usersModel);
}

