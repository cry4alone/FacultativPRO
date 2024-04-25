#ifndef ADMINUSER_H
#define ADMINUSER_H
#include "user.h";

class AdminUser : public User
{
public:
    AdminUser(QString& Login, QString& pass, User::Role role);
};

#endif // ADMINUSER_H
