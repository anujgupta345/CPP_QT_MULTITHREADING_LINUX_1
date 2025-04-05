#include "mylistmodel.h"

MyListModel::MyListModel() {

    items_.append(MyData("Hello1", ""));
    items_.append(MyData("Hello2", ""));
    items_.append(MyData("Hello3", ""));
    items_.append(MyData("Hello4", ""));
    items_.append(MyData("Hello5", ""));
}

int MyListModel::rowCount(const QModelIndex &parent) const
{
    return items_.size();
}

QVariant MyListModel::data(const QModelIndex &index, int role) const
{
    if(role == TextRole)
    {
        return items_[index.row()].text;
    }
    else if(role == ImageRole)
    {
        return items_[index.row()].imgPath;
    }
    return QVariant();
}

QHash<int, QByteArray> MyListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TextRole] = "textRole";
    roles[ImageRole] = "imageRole";
    return roles;
}
