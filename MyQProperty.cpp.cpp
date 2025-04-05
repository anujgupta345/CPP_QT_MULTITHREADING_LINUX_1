#include "MyQProperty.h"

MyQProperty::MyQProperty(QObject *parent)
    : QObject{parent}
{
    count = 1;
}

int MyQProperty::getCount() const
{
    return count;
}

void MyQProperty::setCount(const int &newCount)
{
    if (count == newCount)
        return;
    count = newCount;
    emit countChanged();
}

void MyQProperty::resetCount()
{
    setCount({}); // TODO: Adapt to use your actual default value
}

void MyQProperty::change()
{
 emit countChanged();
}

