#ifndef FACULTATIV_H
#define FACULTATIV_H
#include <QString>

class Facultativ
{
public:
    Facultativ(const int id, const int id_teacher, const QString discipline_name);
    int ID;
    int ID_Teacher;
    QString Discipline_Name;
};

#endif // FACULTATIV_H
