#ifndef STUDENTPERSONALWINDOW_H
#define STUDENTPERSONALWINDOW_H

#include <QDialog>
#include "user.h"
#include "userdb.h"
#include <QMessageBox>

namespace Ui {
class studentpersonalwindow;
}

class studentpersonalwindow : public QDialog
{
    Q_OBJECT

public:
    explicit studentpersonalwindow(QWidget *parent = nullptr, User user = User());
    ~studentpersonalwindow();

private slots:
    void on_CancelButton_clicked();


    void on_ChangeButton_clicked();

private:
    Ui::studentpersonalwindow *ui;
    User m_user;
};

#endif // STUDENTPERSONALWINDOW_H
