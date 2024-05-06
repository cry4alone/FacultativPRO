#ifndef USERDB_H
#define USERDB_H

#include <QString>
#include <QFile>
#include <QtSql>
#include <user.h>
#include "user.h"
#include "facultativ.h"

class UserDb
{
public:
    ~UserDb() {}
    static UserDb& instance();
    int getNextId();
    void addUser(const User& user);
    QVector<User> getAllUsers();
    QPair<QString, int> AuthCheck(QString login, QString pass);
    User getUserByID(int id);
    void addFacultativ(const Facultativ& facultativ);
    bool changeUser(const User& user);
    QVector<Facultativ> getAllFacultatives();
    void deleteUser(int id);
    bool signForFacultativ(int UserID, int FacultativID);
    QVector<Facultativ> getUserFacultatives(int UserID);
private:
    UserDb();
    QSqlDatabase m_database;
    int m_nextId;
};

#endif // USERDB_H
