#include "MyTableModel.h"

MyTableModel::MyTableModel()
{
    m_PersonaData.append(Person("ID", "AGE", "PLACE"));
    m_PersonaData.append(Person("Anuj", "32", "BTM"));
    m_PersonaData.append(Person("Love", "31", "BTM1"));
    m_PersonaData.append(Person("Aaalu", "32", "BTM2"));
    m_PersonaData.append(Person("Anuj", "32", "BTM3"));
}

int MyTableModel::rowCount(const QModelIndex &parent) const
{
    return m_PersonaData.size();
}

int MyTableModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant("");
    }
    if(role == MyRoles::HEADER_ROLE && index.row() == 0)
    {
        switch (index.column()) {
        case 0:
        {
            return "ID";
        }
        break;
        case 1:
        {
            return "Age";
        }
        break;
        case 2:
        {
            return "Place";
        }
        break;
        default:
            return QVariant("");
            break;
        }
    }
    if(role == MyRoles::DATA_ROLE && index.row() > 0)
    {
        switch (index.column()) {
        case 0:
        {
            return m_PersonaData.at(index.row()).name;
        }
            break;
        case 1:
        {
            return m_PersonaData.at(index.row()).age;
        }
            break;
        case 2:
        {
            return m_PersonaData.at(index.row()).place;
        }
            break;
        default:
            return QVariant("");
            break;
        }
    }


    return QVariant("");
}


QHash<int, QByteArray> MyTableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[MyRoles::HEADER_ROLE] = "newRole";
    roles[MyRoles::DATA_ROLE] = "display";

    return roles;
}

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch (section) {
        case 0: return "ID";
        case 1: return "Age";
        case 2: return "Place";
        default: return QVariant("");
        }
    }
    return QVariant("");
}
