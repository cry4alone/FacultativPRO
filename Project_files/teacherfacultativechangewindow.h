#ifndef TEACHERFACULTATIVECHANGEWINDOW_H
#define TEACHERFACULTATIVECHANGEWINDOW_H

#include <QDialog>

namespace Ui {
class teacherFacultativeChangeWindow;
}

class teacherFacultativeChangeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit teacherFacultativeChangeWindow(QWidget *parent = nullptr);
    ~teacherFacultativeChangeWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::teacherFacultativeChangeWindow *ui;
};

#endif // TEACHERFACULTATIVECHANGEWINDOW_H
