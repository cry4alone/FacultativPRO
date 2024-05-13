#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QDialog>
#include "userdb.h"


namespace Ui {
class RegWindow;
}

class RegWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegWindow(QWidget *parent = nullptr);
    ~RegWindow();

private slots:
    void on_OkButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::RegWindow *ui;
};

#endif // REGWINDOW_H
