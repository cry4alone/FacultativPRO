#ifndef CHECKALLUSERSWINDOW_H
#define CHECKALLUSERSWINDOW_H

#include <QDialog>

#include "usersmodel.h"

namespace Ui {
class checkalluserswindow;
}

class checkalluserswindow : public QDialog
{
    Q_OBJECT

public:
    explicit checkalluserswindow(QWidget *parent = nullptr);
    ~checkalluserswindow();

private slots:
    void on_ButtonBack_clicked();

private:
    Ui::checkalluserswindow *ui;
    UsersModel *m_usersModel;
};

#endif // CHECKALLUSERSWINDOW_H
