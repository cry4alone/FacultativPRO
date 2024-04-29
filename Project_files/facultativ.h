#ifndef FACULTATIV_H
#define FACULTATIV_H
#include <QString>

class Facultativ
{
public:
    Facultativ(const int id, const int id_teacher, const QString discipline_name, const QString Teacher_Name, const QString Teacher_Surname);
    Facultativ();
    int ID;
    int ID_Teacher;
    QString Discipline_Name;
    QString Teacher_Name;
    QString Teacher_Surname;
};

#endif // FACULTATIV_H
