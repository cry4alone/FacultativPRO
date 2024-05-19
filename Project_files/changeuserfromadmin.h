#ifndef CHANGEUSERFROMADMIN_H
#define CHANGEUSERFROMADMIN_H

#include <QDialog>
#include "userdb.h"
#include <QString>
#include <QMessageBox>
#include <QRegularExpressionValidator>
#include <QRegularExpression>

namespace Ui {
class ChangeUserFromAdmin;
}

class ChangeUserFromAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeUserFromAdmin(int userID ,QWidget *parent = nullptr);
    ~ChangeUserFromAdmin();

private slots:


    void on_changeButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::ChangeUserFromAdmin *ui;
    int m_userID;
    User user;
};

#endif // CHANGEUSERFROMADMIN_H
