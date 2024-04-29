#ifndef SIGNFORFACULTATIVWINDOW_H
#define SIGNFORFACULTATIVWINDOW_H

#include <QDialog>
#include "facultativesmodel.h"
#include <QMessageBox>

namespace Ui {
class signForFacultativWindow;
}

class signForFacultativWindow : public QDialog
{
    Q_OBJECT

public:
    explicit signForFacultativWindow(QWidget *parent = nullptr);
    ~signForFacultativWindow();

private slots:
    void on_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::signForFacultativWindow *ui;
};

#endif // SIGNFORFACULTATIVWINDOW_H
