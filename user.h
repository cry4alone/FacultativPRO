#ifndef USER_H
#define USER_H
#include <QString>


class User
{
public:
    enum Role {Teacher, Administrator, Student};
    User(const QString& Login, const QString& Password, const Role role);
    User();
    virtual ~User() {}
    int ID;
    QString Login;
    QString Password;
    Role role;
};

#endif // USER_H
