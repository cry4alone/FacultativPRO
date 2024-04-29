#include "facultativesmodel.h"

FacultativesModel::FacultativesModel(QObject *parent)
    : QAbstractTableModel{parent}
{
    m_facultatives = UserDb::instance().getAllFacultatives();
}

FacultativesModel::~FacultativesModel()
{

}

int FacultativesModel::rowCount(const QModelIndex &parent) const
{
    return m_facultatives.size();
}

int FacultativesModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant FacultativesModel::data(const QModelIndex &index, int role) const
{
    if ((index.column() > 3) || (index.row() > m_facultatives.size()))
        return {};
    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return m_facultatives[index.row()].Discipline_Name;
        }
        else if (index.column() == 1) {
            return m_facultatives[index.row()].Teacher_Surname;
        }
        else if (index.column() == 2) {
            return m_facultatives[index.row()].Teacher_Name;
        }
    }
    return {};
}

QVariant FacultativesModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QAbstractTableModel::headerData(section, orientation, role);
    }

    if (orientation == Qt::Horizontal)
    {
        switch (section) {
        case 0:
            return "Discipline Name";
        case 1:
            return "Surname";
        case 2:
            return "Name";
        default:
            break;
        }
    }

    return QAbstractTableModel::headerData(section, orientation, role);
}
