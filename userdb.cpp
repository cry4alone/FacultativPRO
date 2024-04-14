#include <QTextStream>
#include <QDebug>

#include "userdb.h"

UserDb::UserDb()
    : m_usersCsv("users.csv")
{
    if (m_usersCsv.exists()) {
        if (m_usersCsv.open(QFile::ReadOnly)) {
            // UUID
           // TODO: find max id!
        }

        if (m_usersCsv.open(QFile::Append)) {
            qInfo() << "file for users already exists";
        }
    }
    else {

    }

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

void UserDb::addUser(const User& user)
{
    QTextStream ts(&m_usersCsv);
    ts << m_nextId << "; " << "\n"; // TODO: ...
}
