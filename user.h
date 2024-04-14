#ifndef USER_H
#define USER_H
#include <QString>


class User
{
public:

    enum Role {
        admin, teacher, student
    };

public:
    User();
    QString Name;
    QString Surname;
    Role role;
};

#endif // USER_H
