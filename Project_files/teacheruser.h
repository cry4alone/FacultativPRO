#ifndef TEACHERUSER_H
#define TEACHERUSER_H
#include "user.h"

class TeacherUser : public User
{
public:
    TeacherUser(const QString& Login, const QString& Password, const QString& Name, const QString& Surname, const Role role);
    QString Name;
    QString Surname;
    QString Group;
};

#endif // TEACHERUSER_H
