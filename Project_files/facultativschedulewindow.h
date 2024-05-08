#ifndef FACULTATIVSCHEDULEWINDOW_H
#define FACULTATIVSCHEDULEWINDOW_H

#include <QDialog>

namespace Ui {
class facultativScheduleWindow;
}

class facultativScheduleWindow : public QDialog
{
    Q_OBJECT

public:
    explicit facultativScheduleWindow(QWidget *parent = nullptr);
    ~facultativScheduleWindow();

private slots:
    void on_backButton_clicked();

private:
    Ui::facultativScheduleWindow *ui;
};

#endif // FACULTATIVSCHEDULEWINDOW_H
