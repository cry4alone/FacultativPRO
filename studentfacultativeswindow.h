#ifndef STUDENTFACULTATIVESWINDOW_H
#define STUDENTFACULTATIVESWINDOW_H

#include <QDialog>
#include "facultativesmodel.h"

namespace Ui {
class studentfacultativeswindow;
}

class studentfacultativeswindow : public QDialog
{
    Q_OBJECT

public:
    explicit studentfacultativeswindow(QWidget *parent = nullptr);
    ~studentfacultativeswindow();

private slots:
    void on_ButtonBack_clicked();

private:
    Ui::studentfacultativeswindow *ui;
};

#endif // STUDENTFACULTATIVESWINDOW_H
