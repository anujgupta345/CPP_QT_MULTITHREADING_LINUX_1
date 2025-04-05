#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //to call using invoke method of QMetaobject function should either be Q_INVOKABLE or public slots
    Q_INVOKABLE void drawPixmapUsingLabelAndStyleusingQPainter();
    void saveQImageOnDiskUsingLabelAndStyleusingQPainter();
};
#endif // WIDGET_H
