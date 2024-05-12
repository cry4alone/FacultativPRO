#ifndef STUDENTSMODEL_H
#define STUDENTSMODEL_H

#include <QAbstractTableModel>
#include "user.h"
#include <QVector>
#include "userdb.h"

class StudentsModel : public QAbstractTableModel
{
public:
    explicit StudentsModel(QObject *parent = nullptr, int FacID = -1);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVector<int> getChangedRows() const;
    void clearChangedRows();
    QVector<QPair<int, int>> getChangedUsers() const;
    QVector<int> m_tempFinalGrades; //TODO: убрать его в pirvate и написать clear метод
private:
    QVector<User> m_users;
    QVector<int> m_ChangedRows;
    const int FinalGradeColumn = 3;
};

#endif // STUDENTSMODEL_H
