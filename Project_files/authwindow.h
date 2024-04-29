#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QDialog>

#include "user.h"

namespace Ui {
class AuthWindow;
}

class AuthWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();

signals:
    void userEntered(User::Role, int);

private slots:
    void on_LoginButton_clicked();

    void on_RegistrationButton_clicked();

private:
    Ui::AuthWindow *ui;
};

#endif // AUTHWINDOW_H
