#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H
#include <QList>
#include <QAbstractTableModel>

class Person
{
public:
    QString name;
    QString age;
    QString place;
    Person(QString name,
           QString age,
           QString place)
    {
        this->name = name;
        this->age = age;
        this->place = place;
    }
};

class MyTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyTableModel();
enum MyRoles
{
        HEADER_ROLE = Qt::UserRole + 1,
        DATA_ROLE = HEADER_ROLE+1
};
    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    QList<Person> m_PersonaData;
};

#endif // MYTABLEMODEL_H
