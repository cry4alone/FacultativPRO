#include "facultativesmodel.h"

FacultativesModel::FacultativesModel(QObject *parent, bool mode, int UserID)
    : QAbstractTableModel{parent}
{
    if (mode) //0 - personal4sudent 1 - allfacultatives
    {
        m_facultatives = UserDb::instance().getAllFacultatives();
    }
    else
    {
        m_facultatives = UserDb::instance().getUserFacultatives(UserID);
    }

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
    return 4;
}

QVariant FacultativesModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::UserRole) { // возврат значения id выделенной строки
        if (index.column() == 0) {
            return m_facultatives[index.row()].ID;
        }
    }
    if ((index.column() > 3) || (index.row() > m_facultatives.size()))
        return {};
    if (role == Qt::DisplayRole) {
        if (index.column() == 1) {
            return m_facultatives[index.row()].Discipline_Name;
        }
        else if (index.column() == 2) {
            return m_facultatives[index.row()].Teacher_Surname;
        }
        else if (index.column() == 3) {
            return m_facultatives[index.row()].Teacher_Name;
        }
        else if (index.column() == 0)
        {
            return m_facultatives[index.row()].ID;
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
        case 1:
            return "Discipline Name";
        case 2:
            return "Teacher Surname";
        case 3:
            return "Teacher Name";
        case 0:
            return "ID";
        default:
            break;
        }
    }

    return QAbstractTableModel::headerData(section, orientation, role);
}
