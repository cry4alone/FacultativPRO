// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "user.h"

User::User(const QString& Login, const QString& Password, const Role role, const QString& name, const QString& surname, const QString& group)
{
    this ->ID = 0;
    this ->Login = Login;
    this ->Password = Password;
    this ->role = role;
    this ->Name = name;
    this ->Surname = surname;
    this ->Group = group;
};
User::User(const int& id,const QString& Login, const QString& Password, const Role role, const QString& name, const QString& surname, const QString& group)
{
    this ->ID = id;
    this ->Login = Login;
    this ->Password = Password;
    this ->role = role;
    this ->Name = name;
    this ->Surname = surname;
    this ->Group = group;
};
User::User(){};
