#include <QTextStream>
#include <QDebug>
#include "userdb.h"
#include "studentuser.h"
#include "adminuser.h"
#include "teacheruser.h"


UserDb::UserDb()
{
    QSqlDatabase m_database = QSqlDatabase::addDatabase("QSQLITE"); //TODO добавить как поле
    m_database.setDatabaseName("FacultativPRO.sqlite");
    if (!m_database.open()) {
        qDebug()<<"Не удалось открыть базу данных";
    }

}

UserDb& UserDb::instance()
{
    static UserDb db;
    return db;
}

int UserDb::getNextId() {

    QSqlQuery query(m_database);
    query.prepare("SELECT MAX(ID) FROM Users");
    if (!query.exec()) {
        qWarning() << "Failed to execute query: " << query.lastError().text();
        return 1;
    }
    if (query.next()) {
        int m_nextId = query.value(0).toInt();
        m_database.close();
        return m_nextId + 1;
    }
}

QVector<User> UserDb::getAllUsers()
{
    QVector<User> users;
    User user;
    QSqlQuery query(m_database);
    if (!query.exec("SELECT * FROM Users"))
    {
        qWarning() << "Failed to execute query: " << query.lastError().text();
        return users;
    }

    while (query.next())
    {
        int id = query.value(0).toInt();
        QString roleSt = query.value(3).toString();
        QString login = query.value(1).toString();
        QString password = query.value(2).toString();
        QString name = query.value(4).toString();
        QString surname = query.value(5).toString();
        QString group = query.value(6).toString();
        User::Role role;
        if (roleSt == "2") {
            role = User::Role::Student;
        } else if (roleSt == "1") {
            role = User::Role::Teacher;
        } else if (roleSt == "0") {
            role = User::Role::Administrator;
        }
        user = User(id, login, password, role, name, surname, group);
        users.append(user);
    }
    m_database.close();
    return users;
}

User UserDb::getUserByID(int id)
{
    qDebug() << id;
    QSqlQuery query(m_database);
    query.prepare("SELECT * FROM Users WHERE ID = :id");
    query.bindValue(":id", id);
    if (!query.exec())
    {
        qWarning() << "Failed to execute query: " << query.lastError().text();
    }

    if (query.next())
    {
        qDebug() << "Я ТУТ";
        QString roleSt = query.value(3).toString();
        QString login = query.value(1).toString();
        QString password = query.value(2).toString();
        QString name = query.value(4).toString();
        QString surname = query.value(5).toString();
        QString group = query.value(6).toString();
        User::Role role;
        if (roleSt == "2") {
            role = User::Role::Student;
        } else if (roleSt == "1") {
            role = User::Role::Teacher;
        } else if (roleSt == "0") {
            role = User::Role::Administrator;
        }
        User user = User(id, login, password, role, name, surname, group);
        m_database.close();
        return user;
    }
    return User();
}

void UserDb::addUser(const User& user)
{
    m_nextId = getNextId();
    QSqlQuery query(m_database);
    query.prepare("INSERT INTO Users (ID, Login, Password, Role, Name, Surname, GroupNum) VALUES (:id, :login, :password, :role, :name, :surname, :groupnum)");
        query.bindValue(":id", m_nextId);
        query.bindValue(":login", user.Login);
        query.bindValue(":password", user.Password);
        switch (user.role)
        {
            case User::Role::Student:
                query.bindValue(":role", 2);
                query.bindValue(":name", user.Name);
                query.bindValue(":surname", user.Surname);
                query.bindValue(":groupnum", user.Group);
                break;
            case User::Role::Teacher:
                query.bindValue(":role", 1);
                query.bindValue(":name", user.Name);
                query.bindValue(":surname", user.Surname);
                break;
            case User::Role::Administrator:
                query.bindValue(":role", 0);
                break;
        }
        query.exec();
}

QString UserDb::AuthCheck(QString login, QString pass)
{
    QSqlQuery query(m_database);
    query.prepare("SELECT Role FROM Users WHERE Login = :login AND Password = :password");
    query.bindValue(":login", login);
    query.bindValue(":password", pass);

    if (!query.exec()) {
        qWarning() << "Failed to execute query: " << query.lastError().text();
        m_database.close();
        return "None";
    }

    if (query.next()) {
        QString role = query.value(0).toString();
        m_database.close();
        return role;
    }

    m_database.close();
    return "None";
}

void UserDb::addFacultativ(const Facultativ& facultativ)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Facultatives (ID_Teacher, Discipline_Name, Type_of_Study) VALUES (:id_teacher, :discipline_name, :type_of_study");
    query.bindValue(":id_teacher", facultativ.ID_Teacher);
    query.bindValue(":discipline_name", facultativ.Discipline_Name);
    query.bindValue(":type_of_study", facultativ.Type_of_Study);

    if (!query.exec())
    {
        qWarning() << "Failed to execute query: " << query.lastError().text();
    }

    if (query.next())
    {
        m_database.close();
    }
}

