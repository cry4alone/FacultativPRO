#include "usersmodel.h"
#include "userdb.h"

#include <QDebug>

UsersModel::UsersModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    //m_users = UserDb::instance().getAllUsers();

    m_users = {
        new User("Login1", "Pass1", User::Administrator),
        new User("Login2", "Pass2", User::Student),
        new User("Login3", "Pass3", User::Teacher),
        new User("Login4", "Pass4", User::Administrator)
    };
}

UsersModel::~UsersModel()
{
    for (int i = 0; i < m_users.size(); ++i)
        delete m_users[i];
}


int UsersModel::rowCount(const QModelIndex &parent) const
{
    return m_users.size();
}

int UsersModel::columnCount(const QModelIndex &parent) const
{
    return 3; // TODO:
}

QVariant UsersModel::data(const QModelIndex &index, int role) const
{
    qDebug() << index;

    if ((index.column() > 3) || (index.row() > m_users.size()))
        return {};

    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return m_users[index.row()]->Login;
        }
        else if (index.column() == 1) {
            return m_users[index.row()]->Password;
        }
        else if (index.column() == 2) {
            return m_users[index.row()]->role;
        }
    }
    return {};
}

QVariant UsersModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QAbstractTableModel::headerData(section, orientation, role);
    }

    if (orientation == Qt::Horizontal)
    {
        switch (section) {
        case 0:
            return "Login";
        case 1:
            return "Password";
        case 2:
            return "Role";
        default:
            break;
        }
    }
    else if (orientation == Qt::Vertical)
    {
        return QString::number(section + 1);
    }

    return QAbstractTableModel::headerData(section, orientation, role);
}
