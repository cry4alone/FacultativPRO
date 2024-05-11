#ifndef STUDENTFACULTATIVESWINDOW_H
#define STUDENTFACULTATIVESWINDOW_H

#include <QMainWindow>
#include "facultativesmodel.h"
#include "user.h"
#include "studentfacultativeswindow.h"
#include "signforfacultativwindow.h"
#include "facultativschedulewindow.h"

namespace Ui {
class studentfacultativeswindow;
}

class studentfacultativeswindow : public QDialog
{
    Q_OBJECT

public:
    explicit studentfacultativeswindow(QWidget *parent = nullptr, User m_user = User());
    ~studentfacultativeswindow();

private slots:
    void on_ButtonBack_clicked();

    void on_signFacultativButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::studentfacultativeswindow *ui;
    User m_user;
    std::unique_ptr<facultativScheduleWindow> fsw;
    FacultativesModel *fac_mod;
};

#endif // STUDENTFACULTATIVESWINDOW_H
