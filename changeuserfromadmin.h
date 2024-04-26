#ifndef CHANGEUSERFROMADMIN_H
#define CHANGEUSERFROMADMIN_H

#include <QDialog>
#include "userdb.h"
#include <QString>
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
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ChangeUserFromAdmin *ui;
    int m_userID;
    User user;
};

#endif // CHANGEUSERFROMADMIN_H
