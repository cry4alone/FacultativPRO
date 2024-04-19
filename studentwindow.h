#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QMainWindow>
#include "studentpersonalwindow.h"
#include "studentfacultativeswindow.h"

namespace Ui {
class studentwindow;
}

class studentwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit studentwindow(QWidget *parent = nullptr);
    ~studentwindow();

signals:
    void logout();

private slots:
    void on_changeUserButton_clicked();

    void on_personalAreaButton_clicked();

    void on_facultativButton_clicked();

private:
    Ui::studentwindow *ui;
};

#endif // STUDENTWINDOW_H
