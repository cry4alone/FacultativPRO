#include "signforfacultativwindow.h"
#include "ui_signforfacultativwindow.h"

signForFacultativWindow::signForFacultativWindow(QWidget *parent, int UserID) :
    QDialog(parent),
    ui(new Ui::signForFacultativWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Sign");
    m_UserID = UserID;
    ui->tableView->setModel(new FacultativesModel(nullptr, 1, 0));
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

signForFacultativWindow::~signForFacultativWindow()
{
    delete ui;
}

void signForFacultativWindow::on_pushButton_clicked()
{
    close();
}


void signForFacultativWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    const auto mi = index.siblingAtColumn(0);
    int facultativeId = ui->tableView->model()->data(mi, Qt::UserRole).toInt();
    QMessageBox::StandardButton result = QMessageBox::question(this,"Confirmation", "Are you sure you want to sign up for this facultativ?", QMessageBox::Yes|QMessageBox::No);
    //TODO : обработать нажатия кнопок
    if (result == QMessageBox::Yes)
    {
        qDebug() << facultativeId << m_UserID;
        UserDb::instance().signForFacultativ(m_UserID, facultativeId);
        close();
    }
}





