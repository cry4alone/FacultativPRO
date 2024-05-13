#ifndef FACULTATIVSCHEDULEWINDOW_H
#define FACULTATIVSCHEDULEWINDOW_H

#include <QDialog>
#include "facultativ.h"
#include <QTextCharFormat>
#include "userdb.h"

namespace Ui {
class facultativScheduleWindow;
}

class facultativScheduleWindow : public QDialog
{
    Q_OBJECT

public:
    explicit facultativScheduleWindow(QWidget *parent = nullptr, Facultativ facultativ = Facultativ(), int userID = -100);
    ~facultativScheduleWindow();
private slots:
    void on_backButton_clicked();

    void on_unsignButton_clicked();

private:
    Ui::facultativScheduleWindow *ui;
    Facultativ m_facultativ;
    int m_UserID;
    void highlightweeklydates(Qt::DayOfWeek DayOfWeek, QDate Start_Date, QDate End_Date);
    void setAllData(Qt::DayOfWeek DayOfWeek);
};

#endif // FACULTATIVSCHEDULEWINDOW_H
