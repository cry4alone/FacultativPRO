#ifndef FACULTATIV_H
#define FACULTATIV_H
#include <QString>
#include <QDate>

class Facultativ
{

public:
    enum Type_of_Lesson
    {
        Lection,
        Laboratory_work,
        Practice_work
    };
    Facultativ(const int id, const int id_teacher, const QString discipline_name, const QString teacher_name, const QString teacher_surname, const int day_of_week, const QDate start_date, const QDate end_date, const Type_of_Lesson type_of_lesson)
                : ID(id), ID_Teacher(id_teacher), Discipline_Name(discipline_name), Teacher_Name(teacher_name), Teacher_Surname(teacher_surname), Day_of_Week(day_of_week), Start_Date(start_date), End_Date(end_date), Type_of_lesson(type_of_lesson) {}
    Facultativ(const int id, const int id_teacher, const QString discipline_name, const QString Teacher_Name, const QString Teacher_Surname);
    Facultativ(QString discipline_name, QDate start_date, QDate end_date, int day_of_week, Type_of_Lesson type_of_lesson)
            : Discipline_Name(discipline_name), Start_Date(start_date), End_Date(end_date), Day_of_Week(day_of_week), Type_of_lesson(type_of_lesson) {}
    Facultativ();
    int ID;
    int ID_Teacher;
    QString Discipline_Name;
    QString Teacher_Name;
    QString Teacher_Surname;
    int Day_of_Week;
    QDate Start_Date;
    QDate End_Date;
    Type_of_Lesson Type_of_lesson;
};

#endif // FACULTATIV_H
