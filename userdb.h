#ifndef USERDB_H
#define USERDB_H

#include <QString>
#include <QFile>

#include "user.h"

class UserDb
{
public:
    ~UserDb() {}

    // static bool itialize();
    static UserDb& instance();

    User getUserByLoginAndPassword(QString login, QString pass);
    bool hasUserWithLogin(QString login);
    int getNextId();
    void addUser(const User& user);
    QString AuthCheck(QString login, QString pass);
    //...

private:
    UserDb();
    QFile m_usersCsv;
    int m_nextId;
};

#endif // USERDB_H
