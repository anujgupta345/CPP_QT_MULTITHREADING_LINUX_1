#ifndef MYLISTMODEL_H
#define MYLISTMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QList>

struct MyData
{
    QString text;
    QString imgPath;
    MyData(QString text, QString imgPath)
    {
        this->text = text;
        this->imgPath = imgPath;
    }

};

class MyListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    MyListModel();
    enum MyRoles
    {
        TextRole = Qt::UserRole +1,
        ImageRole

    };
    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QList<MyData> items_;

    // QAbstractItemModel interface
public:
    QHash<int, QByteArray> roleNames() const;
};

#endif // MYLISTMODEL_H
