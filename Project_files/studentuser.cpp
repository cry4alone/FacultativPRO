#include "studentuser.h"

StudentUser::StudentUser(const QString& Login, const QString& Password, const QString& Name, const QString& Surname, const QString& Group, const Role Role)
{
    this ->ID = 0;
    this ->Login = Login;
    this ->Password = Password;
    this ->Name = Name;
    this ->Surname = Surname;
    this ->Group = Group;
    this ->role = Role;
}
