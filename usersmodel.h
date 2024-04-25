#ifndef USERSMODEL_H
#define USERSMODEL_H

#include <QAbstractTableModel>
#include <QSharedPointer>
#include <QVector>

#include "user.h"

class UsersModel : public QAbstractTableModel
{
public:
    explicit UsersModel(QObject *parent = nullptr);
    ~UsersModel();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QVector<User> m_users;
};

#endif // USERSMODEL_H
