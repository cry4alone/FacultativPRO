// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "teachercreatefacultative.h"
#include "ui_teachercreatefacultative.h"

teacherCreateFacultative::teacherCreateFacultative(QWidget *parent, int UserID) :
    QDialog(parent),
    ui(new Ui::teacherCreateFacultative)
{
    ui->setupUi(this);
    this->setWindowTitle("Create Facultative");
    setWindowIcon(QIcon(":/icon/Icon"));
    showMaximized();
    m_UserID = UserID;
}

teacherCreateFacultative::~teacherCreateFacultative()
{
    delete ui;
}

void teacherCreateFacultative::on_backButton_clicked()
{
    close();
}


void teacherCreateFacultative::on_createButton_clicked()
{
    QString Discipline_name = ui->nameEdit->text();
    if (Discipline_name.trimmed() == "")
    {
        QMessageBox::warning(this, "Warning", "Discipline Name can't be empty!");
        return;
    }
    QDate start_date = ui->startDateEdit->date();
    QDate end_date = ui->endDateEdit->date();
    if(checkDate(start_date, end_date))
    {
        return;
    }
    QMessageBox::StandardButton result = QMessageBox::question(this,"Confirmation", "Are you sure you want to add facultative?", QMessageBox::Yes|QMessageBox::No);
    //TODO : обработать нажатия кнопок
    if (result == QMessageBox::Yes)
    {
        int day_of_week = ui->dayBox->currentIndex();
        int type_of_lesson = ui->laboratoryBox->currentIndex();
        QString type_of_lesson_string  = QString::number(type_of_lesson);
        Facultativ::Type_of_Lesson Type_of_lesson;
        if (type_of_lesson_string == "0")
        {
            Type_of_lesson = Facultativ::Type_of_Lesson::Lection;
        }
        else if (type_of_lesson_string == "1")
        {
            Type_of_lesson = Facultativ::Type_of_Lesson::Laboratory_work;
        }
        else
        {
            Type_of_lesson = Facultativ::Type_of_Lesson::Practice_work;
        }
        Facultativ facultative(Discipline_name, start_date, end_date, day_of_week, Type_of_lesson);
        facultative.ID_Teacher = m_UserID;
        bool result = UserDb::instance().addFacultativ(facultative);
        if (result)
        {
            QMessageBox::information(this, "Information", "Facultative added successfully!");
            close();
        }
    }
}

bool teacherCreateFacultative::checkDate(QDate start, QDate finish)
{
    QDate currDate = QDate::currentDate();
    if ((start < currDate || finish < currDate) || (start == finish))
    {
        QMessageBox::warning(this, "Warning", "Check your dates!");
        return true;
    }
    else if (start > finish)
    {
        QMessageBox::warning(this, "Warning", "Start date is bigger than end date!");
        return true;
    }
    return false;
}

