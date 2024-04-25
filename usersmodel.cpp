#include "usersmodel.h"
#include "userdb.h"

#include <QDebug>

UsersModel::UsersModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    m_users = UserDb::instance().getAllUsers();
}

UsersModel::~UsersModel()
{
}


int UsersModel::rowCount(const QModelIndex &parent) const
{
    return m_users.size();
}

int UsersModel::columnCount(const QModelIndex &parent) const
{
    return 7; // TODO:
}

QVariant UsersModel::data(const QModelIndex &index, int role) const
{
    qDebug() << index;

    if ((index.column() > 7) || (index.row() > m_users.size()))
        return {};

    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return m_users[index.row()].ID;
        }
        else if (index.column() == 1) {
            return m_users[index.row()].Login;
        }
        else if (index.column() == 2) {
            return m_users[index.row()].Password;
        }
        else if (index.column() == 3) {
            return m_users[index.row()].role;
        }
        else if (index.column() == 4) {
            return m_users[index.row()].Name;
        }
        else if (index.column() == 5) {
            return m_users[index.row()].Surname;
        }
        else if (index.column() == 6) {
            return m_users[index.row()].Group;
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
            return "ID";
        case 1:
            return "Login";
        case 2:
            return "Password";
        case 3:
            return "Role";
        case 4:
            return "Name";
        case 5:
            return "Surname";
        case 6:
            return "Group";
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
