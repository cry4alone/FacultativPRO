#ifndef USER_H
#define USER_H
#include <QString>


class User
{
public:
    enum Role {Teacher, Administrator, Student};
    User(const int& id,const QString& Login, const QString& Password, const Role role, const QString& name, const QString& surname, const QString& group);
    User(const QString& Login, const QString& Password, const Role role, const QString& name, const QString& surname, const QString& group);
    User();
    virtual ~User() {}
    int ID;
    QString Login;
    QString Password;
    Role role;
    QString Name;
    QString Surname;
    QString Group;
};

#endif // USER_H
