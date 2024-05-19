#ifndef FACULTATIVESMODEL_H
#define FACULTATIVESMODEL_H
#include <QAbstractTableModel>
#include <QVector>
#include "facultativ.h"
#include "userdb.h"

class FacultativesModel : public QAbstractTableModel
{
public:
    explicit FacultativesModel(QObject *parent = nullptr, int UserID = 0);
    ~FacultativesModel();
private:
    QVector<Facultativ> m_facultatives;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void addFacultativ(Facultativ facultativ);
    int size();
    void setAllFacultatives();
    void setIdFacultatives(int UserID);
    void setTeacherFacultatives(int UserID);
    void deleteFacultatives(int index, int FacID);
};

#endif // FACULTATIVESMODEL_H

