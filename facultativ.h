#ifndef FACULTATIV_H
#define FACULTATIV_H
#include <QString>

class Facultativ
{
public:
    Facultativ(const int id, const int id_teacher, const QString discipline_name, const QString type_of_study);
    int ID;
    int ID_Teacher;
    QString Discipline_Name;
    QString Type_of_Study;
};

#endif // FACULTATIV_H
