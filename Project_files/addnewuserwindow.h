// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifndef ADDNEWUSERWINDOW_H
#define ADDNEWUSERWINDOW_H

#include <QDialog>
#include <QString>
#include "user.h"
#include <qmessagebox.h>

namespace Ui {
class AddNewUserWindow;
}

class AddNewUserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewUserWindow(QWidget *parent = nullptr);
    ~AddNewUserWindow();

private slots:
    void on_pushBtnCancel_clicked();

    void on_pushBtnOk_clicked();

private:
    Ui::AddNewUserWindow *ui;
    bool isNumber(QString &str);
};

#endif // ADDNEWUSERWINDOW_H
