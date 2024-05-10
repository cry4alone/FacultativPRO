#include "teachercreatefacultative.h"
#include "ui_teachercreatefacultative.h"

teacherCreateFacultative::teacherCreateFacultative(QWidget *parent, int UserID) :
    QDialog(parent),
    ui(new Ui::teacherCreateFacultative)
{
    ui->setupUi(this);
    m_UserID = UserID;
    QSvgRenderer renderer(QString("calender-2389150.svg"));
    QPixmap pixmap(renderer.defaultSize());
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    renderer.render(&painter);
    ui->picture->setPixmap(pixmap);
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
    QMessageBox::StandardButton result = QMessageBox::question(this,"Confirmation", "Are you sure you want to add facultative?", QMessageBox::Yes|QMessageBox::No);
    //TODO : обработать нажатия кнопок
    if (result == QMessageBox::Yes)
    {
        QString Discipline_name = ui->nameEdit->text();
        QDate start_date = ui->startDateEdit->date();
        QDate end_date = ui->endDateEdit->date();
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


