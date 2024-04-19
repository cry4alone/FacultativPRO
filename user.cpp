#include "user.h"

User::User(const QString& Login, const QString& Password, const Role role)
{
    this ->ID = 0;
    this ->Login = Login;
    this ->Password = Password;
    this ->role = role;
};
User::User(){};
