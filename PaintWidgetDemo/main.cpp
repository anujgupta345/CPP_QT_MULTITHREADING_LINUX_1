#include "widget.h"

#include <QApplication>
#include <QMetaObject>
#include <QMetaMethod>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //two ways to use meta object system to call method
    Widget w;
    //to call using invoke method of QMetaobject function should either be Q_INVOKABLE or public slots
    //QMetaObject::invokeMethod(&w, "drawPixmapUsingLabelAndStyleusingQPainter", Qt::DirectConnection);

    int index = w.metaObject()->indexOfMethod("drawPixmapUsingLabelAndStyleusingQPainter()");// here need to pass fun name with
    //()
    QMetaMethod mymethod = w.metaObject()->method(index);
    mymethod.invoke(&w, Qt::DirectConnection);
    w.show();
    return a.exec();
}
