#include "facultativschedulewindow.h"
#include "ui_facultativschedulewindow.h"

facultativScheduleWindow::facultativScheduleWindow(QWidget *parent, Facultativ facultativ, int UserID) :
    QDialog(parent),
    ui(new Ui::facultativScheduleWindow)
{
    Qt::DayOfWeek DayOfWeek;
    switch (facultativ.Day_of_Week)
    {
        case 0:
            DayOfWeek = Qt::Monday;
            break;
        case 1:
            DayOfWeek = Qt::Tuesday;
            break;
        case 2:
            DayOfWeek = Qt::Wednesday;
            break;
        case 3:
            DayOfWeek = Qt::Thursday;
            break;
        case 4:
            DayOfWeek = Qt::Friday;
            break;
        case 5:
            DayOfWeek = Qt::Saturday;
            break;
        case 6:
            DayOfWeek = Qt::Sunday;
            break;
    }

    ui->setupUi(this);
    m_facultativ = facultativ;
    m_UserID = UserID;
    ui->label_facultativ_name->setText(m_facultativ.Discipline_Name + " facultativ");
    ui->label_teacher->setText("Your Teacher: " + m_facultativ.Teacher_Name + " " + m_facultativ.Teacher_Surname);
    QList<QDate> datesToHighlight = {facultativ.Start_Date, facultativ.End_Date};
    QTextCharFormat format;
    highlightweeklydates(DayOfWeek, facultativ.Start_Date, facultativ.End_Date);
    format.setBackground(Qt::blue);
    foreach (const QDate &date, datesToHighlight)
    {
        ui->calendarWidget->setDateTextFormat(date, format); // Highlight the date
    }
}

facultativScheduleWindow::~facultativScheduleWindow()
{
    delete ui;
}

void facultativScheduleWindow::on_backButton_clicked()
{
    close();
}

void facultativScheduleWindow::highlightweeklydates(Qt::DayOfWeek DayOfWeek, QDate Start_Date, QDate End_Date)
{

    QTextCharFormat format;
    format.setBackground(Qt::green);
    for (QDate date = Start_Date; date <= End_Date; date = date.addDays(1)) {
        if (date.dayOfWeek() == DayOfWeek) { // Check if the date falls on a Friday
            ui->calendarWidget->setDateTextFormat(date, format); // Highlight the date
        }
    }
}

void facultativScheduleWindow::on_unsignButton_clicked()
{
    UserDb::instance().deleteStudentFromFacultative(m_UserID, m_facultativ.ID);
    close();
}

