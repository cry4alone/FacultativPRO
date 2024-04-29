#ifndef STUDENTUSER_H
#define STUDENTUSER_H
#include "user.h"
#include "studentuser.h"

class StudentUser : public User
{
public:
    StudentUser(const QString& Login, const QString& Password, const QString& Name, const QString& Surname, const QString& Group, const Role role);
    QString Name;
    QString Surname;
    QString Group;
};

#endif // STUDENTUSER_H
