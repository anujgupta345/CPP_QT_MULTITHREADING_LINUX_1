#ifndef MYQPROPERTY_H
#define MYQPROPERTY_H

#include <QObject>

class MyQProperty : public QObject
{
    Q_OBJECT
public:
    explicit MyQProperty(QObject *parent = nullptr);

    int getCount() const;
    void setCount(const int &newCount);
    void resetCount();
    Q_INVOKABLE void change();
signals:
    void countChanged();

private: int count;
    Q_PROPERTY(int count READ getCount WRITE setCount RESET resetCount NOTIFY countChanged)
};

#endif // MYQPROPERTY_H
