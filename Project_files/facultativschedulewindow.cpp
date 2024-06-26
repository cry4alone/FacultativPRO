// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "facultativschedulewindow.h"
#include "ui_facultativschedulewindow.h"

facultativScheduleWindow::facultativScheduleWindow(QWidget *parent, Facultativ facultativ, int UserID) :
    QDialog(parent),
    ui(new Ui::facultativScheduleWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Facultative Information");
    setWindowIcon(QIcon(":/icon/Icon"));
    show();
    moveCentre();
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


    m_facultativ = facultativ;
    m_UserID = UserID;

    setAllData(DayOfWeek);
}

void facultativScheduleWindow::moveCentre()
{
    QRect screenGeometry = QApplication::primaryScreen()->availableGeometry();
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;
    this->move(x, y);
}

void facultativScheduleWindow::setAllData(Qt::DayOfWeek DayOfWeek)
{
    ui->label_facultativ_name->setText(m_facultativ.Discipline_Name + " facultativ");
    ui->label_teacher->setText("Your Teacher: " + m_facultativ.Teacher_Name + " " + m_facultativ.Teacher_Surname);
    int final_grade = UserDb::instance().getFinalGrade(m_UserID, m_facultativ.ID);
    QString lesson;
    switch(m_facultativ.Type_of_lesson)
    {
        case 0:
            lesson = "Lection";
            break;
        case 1:
            lesson = "Laboratory";
            break;
        case 2:
            lesson = "Practice";
            break;
    }

    ui->label_lesson_type->setText("Lesson Type: " + lesson);
    ui->label_grade->setText("Your Grade: " + QString::number(final_grade));
    highlightweeklydates(DayOfWeek, m_facultativ.Start_Date, m_facultativ.End_Date);
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
    QList<QDate> datesToHighlight = {Start_Date, End_Date};
    QTextCharFormat format;
    format.setBackground(Qt::blue);
    foreach (const QDate &date, datesToHighlight)
    {
        ui->calendarWidget->setDateTextFormat(date, format); // Highlight the date
    }
    format.setBackground(Qt::green);
    for (QDate date = Start_Date; date <= End_Date; date = date.addDays(1)) {
        if (date.dayOfWeek() == DayOfWeek) {
            ui->calendarWidget->setDateTextFormat(date, format); // Highlight the date
        }
    }
}

void facultativScheduleWindow::on_unsignButton_clicked()
{
    emit deleteStudentFromFacultative(m_index, m_facultativ.ID);
    UserDb::instance().deleteStudentFromFacultative(m_UserID, m_facultativ.ID);
    close();
}

