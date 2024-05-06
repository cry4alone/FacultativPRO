#include "signforfacultativwindow.h"
#include "ui_signforfacultativwindow.h"

signForFacultativWindow::signForFacultativWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signForFacultativWindow)
{
    ui->setupUi(this);
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
    QMessageBox::question(this,"Confirmation", "Are you sure you want to sign up for this facultativ?", "No", "Yes");
    //TODO : обработать нажатия кнопок
    /*switch (result)
    {
        case QMessageBox::Yes:
            // TODO: код для подтверждения записи на факультатив
            break;
        case QMessageBox::No:
            // ничего не делаем
            break;
        default:
            // ничего не делаем
            break;
    }*/
}




