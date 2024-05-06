#ifndef FACULTATIVESMODELPERSONAL_H
#define FACULTATIVESMODELPERSONAL_H
#include <QAbstractTableModel>
#include <QVector>
#include "facultativ.h"
#include "userdb.h"

class FacultativesModelPersonal : public QAbstractTableModel
{
public:
    explicit FacultativesModelPersonal(QObject *parent = nullptr);
    ~FacultativesModelPersonal();
private:
    QVector<Facultativ> m_facultatives;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

#endif // FACULTATIVESMODELPERSONAL_H

