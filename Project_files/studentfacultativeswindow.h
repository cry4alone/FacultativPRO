#ifndef STUDENTFACULTATIVESWINDOW_H
#define STUDENTFACULTATIVESWINDOW_H

#include <QDialog>
#include "facultativesmodel.h"
#include "user.h"
#include "studentfacultativeswindow.h"
#include "signforfacultativwindow.h"

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

private:
    Ui::studentfacultativeswindow *ui;
    User m_user;
};

#endif // STUDENTFACULTATIVESWINDOW_H
