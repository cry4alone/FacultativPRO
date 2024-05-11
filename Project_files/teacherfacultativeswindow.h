#ifndef TEACHERFACULTATIVESWINDOW_H
#define TEACHERFACULTATIVESWINDOW_H

#include <QDialog>
#include "facultativesmodel.h"
#include "teacherfacultativechangewindow.h"

namespace Ui {
class teacherFacultativesWindow;
}

class teacherFacultativesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit teacherFacultativesWindow(QWidget *parent = nullptr, int UserID = -1);
    ~teacherFacultativesWindow();

private slots:
    void on_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::teacherFacultativesWindow *ui;
};

#endif // TEACHERFACULTATIVESWINDOW_H
