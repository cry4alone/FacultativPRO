#ifndef FACULTATIVESMODEL_H
#define FACULTATIVESMODEL_H
#include <QAbstractTableModel>
#include <QVector>
#include "facultativ.h"
#include "userdb.h"

class FacultativesModel : public QAbstractTableModel
{
public:
    explicit FacultativesModel(QObject *parent = nullptr);
    ~FacultativesModel();
private:
    QVector<Facultativ> m_facultatives;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

#endif // FACULTATIVESMODEL_H

