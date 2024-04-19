#include <QTextStream>
#include <QDebug>
#include "userdb.h"
#include "studentuser.h"
#include "adminuser.h"
#include "teacheruser.h"

UserDb::UserDb()
    : m_usersCsv("users.csv")
{
}

UserDb& UserDb::instance()
{
    static UserDb db;
    return db;
}

User UserDb::getUserByLoginAndPassword(QString login, QString pass)
{

    return User{};
}

bool UserDb::hasUserWithLogin(QString login)
{

}

int UserDb::getNextId() {

    if (!m_usersCsv.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open file for reading: " << m_usersCsv.errorString();
        return 1;
    }

    QTextStream in(&m_usersCsv);
    int maxId = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() >= 1) {
            bool ok;
            int id = fields[0].toInt(&ok);
            if (ok && id > maxId) {
                maxId = id;
            }
        }
    }
    m_usersCsv.close();
    return maxId + 1;
}

void UserDb::addUser(const User& user)
{
    m_nextId = getNextId();
    m_usersCsv.open(QIODevice::Append);
    QTextStream ts(&m_usersCsv);
    ts << m_nextId << ",";
    switch (user.role) {
        case User::Role::Student:
            ts << "Student,";
            break;
        case User::Role::Teacher:
            ts << "Teacher,";
            break;
        case User::Role::Administrator:
            ts << "Administrator,";
            break;
        }

        // Записываем логин и пароль пользователя
        ts << user.Login << "," << user.Password << ",";

        // Записываем имя и фамилию пользователя


        // Преобразуем указатель на базовый класс User в указатель на производный класс
        const StudentUser* studentUser = dynamic_cast<const StudentUser*>(&user);
        const TeacherUser* teacherUser = dynamic_cast<const TeacherUser*>(&user);
        //const AdminUser* adminUser = dynamic_cast<const AdminUser*>(&user);

        // Записываем дополнительные данные в зависимости от типа пользователя
        if (studentUser)
        {
            ts << studentUser->Name << "," << studentUser->Surname << "," << studentUser->Group << "\n";
        }

       else if (teacherUser) {
            ts << teacherUser->Name << "," << teacherUser->Surname << "\n";
        }
        /*
        else if (adminUser) {
            ts << "," << adminUser->phone << "\n";
        }
        */
        m_usersCsv.close();
}

QString UserDb::AuthCheck(QString login, QString pass)
{

    if (!m_usersCsv.open(QIODevice::ReadOnly))
    {
        qWarning() << "Failed to open file for reading: " << m_usersCsv.errorString();
    }
    QTextStream in(&m_usersCsv);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() >= 4) // минимальное количество полей для пользователя
        {
            if (fields[2] == login && fields[3] == pass)
            {
                m_usersCsv.close();
                return fields[1];
            }
        }
    }

    m_usersCsv.close();
    return "None";
}
