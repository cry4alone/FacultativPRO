#ifndef ADDNEWUSERWINDOW_H
#define ADDNEWUSERWINDOW_H

#include <QDialog>

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
};

#endif // ADDNEWUSERWINDOW_H
