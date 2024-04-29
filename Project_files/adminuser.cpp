#include "adminuser.h"

AdminUser::AdminUser(QString& Login, QString& pass, User::Role role)
{
    this ->ID = 0;
    this ->Login = Login;
    this ->Password = pass;
    this ->role = role;
}
