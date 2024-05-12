#include "studentsmodel.h"

StudentsModel::StudentsModel(QObject *parent, int FacID)
    : QAbstractTableModel{parent}
{
    m_users = UserDb::instance().getTeacherUsers(FacID);
}

int StudentsModel::rowCount(const QModelIndex &parent) const
{
    return m_users.size();
}

int StudentsModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant StudentsModel::data(const QModelIndex &index, int role) const
{
    if ((index.column() > 4) || (index.row() > m_users.size()))
        return {};

    if (role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return m_users[index.row()].ID;
        }
        else if (index.column() == 1) {
            return m_users[index.row()].Name;
        }
        else if (index.column() == 2) {
            return m_users[index.row()].Surname;
        }
        else if (index.column() == 3) {
            return m_users[index.row()].FinalGrade;
        }
    }
    return {};
}

QVariant StudentsModel::headerData(int section, Qt::Orientation orientation, int role) const
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
            return "Name";
        case 2:
            return "Surname";
        case 3:
            return "Final_Grade";
        default:
            break;
        }
    }
    return {};
}

Qt::ItemFlags StudentsModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags defaultFlags = QAbstractTableModel::flags(index);
    if (index.column() == FinalGradeColumn) {
        return Qt::ItemIsEditable | defaultFlags;
    }
    return defaultFlags;
}

bool StudentsModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role != Qt::EditRole) {
        return false;
    }

    if (index.column() == FinalGradeColumn) {
        // Сохраняем временное значение FinalGrade для измененной строки
        if (index.row() >= m_tempFinalGrades.size()) {
            m_tempFinalGrades.resize(index.row() + 1);
        }
        m_tempFinalGrades[index.row()] = value.toInt();

        // Добавляем номер измененной строки в список измененных строк
        if (!m_ChangedRows.contains(index.row())) {
            m_ChangedRows.append(index.row());
        }

        // Обновляем значение в модели
        m_users[index.row()].FinalGrade = value.toInt();

        // Вызываем сигнал dataChanged(), чтобы обновить представление
        emit dataChanged(index, index);

        return true;
    }

    return false;
}

QVector<int> StudentsModel::getChangedRows() const
{
    return m_ChangedRows;
}

void StudentsModel::clearChangedRows() {
    m_ChangedRows.clear();
}

QVector<QPair<int, int>> StudentsModel::getChangedUsers() const
{
    QVector<QPair<int, int>> changedUsers;

    for (int row : m_ChangedRows) {
        changedUsers.append(qMakePair(m_users[row].ID, m_tempFinalGrades[row]));
    }

    return changedUsers;
}
