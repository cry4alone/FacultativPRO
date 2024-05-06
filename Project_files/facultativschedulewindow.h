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

private:
    Ui::facultativScheduleWindow *ui;
};

#endif // FACULTATIVSCHEDULEWINDOW_H
