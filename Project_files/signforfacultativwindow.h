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
    explicit signForFacultativWindow(QWidget *parent = nullptr, int UserID = -1);
    ~signForFacultativWindow();

private slots:
    void on_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    int m_UserID;
    Ui::signForFacultativWindow *ui;
};

#endif // SIGNFORFACULTATIVWINDOW_H
