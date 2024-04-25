#include "teacheruser.h"

TeacherUser::TeacherUser(const QString& Login, const QString& Password, const QString& Name, const QString& Surname, const Role role)
{
    this ->ID = 0;
    this ->Login = Login;
    this ->Password = Password;
    this ->Name = Name;
    this ->Surname = Surname;
    this ->role = role;
}
