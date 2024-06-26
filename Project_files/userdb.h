// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#ifndef USERDB_H
#define USERDB_H

#include <QString>
#include <QFile>
#include <QtSql>
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
    bool addFacultativ(const Facultativ& facultativ);
    bool changeUser(const User& user);
    QVector<Facultativ> getAllFacultatives();
    void deleteUser(int id);
    bool signForFacultativ(int UserID, int FacultativID);
    QVector<Facultativ> getUserFacultatives(int UserID);
    Facultativ getFacultativByID(int FacID);
    void deleteStudentFromFacultative(int UserID, int FacultativID);
    QVector<Facultativ> getTeacherFacultativ(int UserID);
    QVector<User> getTeacherUsers(int FacID);
    void setFinalGrade(int userId, int finalGrade, int FacID);
    void changeFacultativ(const Facultativ& facultativ);
    int getFinalGrade(int UserID, int FacID);
    QVector<User> getOnlySpecificRoleUsers(int role);
    void deleteFacultative(int FacID);
private:
    UserDb();
    QSqlDatabase m_database;
    int m_nextId;
};

#endif // USERDB_H
