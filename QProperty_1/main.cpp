#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "MyQProperty.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/QProperty/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    MyQProperty mymodel;
    engine.rootContext()->setContextProperty("mymodel", &mymodel);
    engine.load(url);


    return app.exec();
}
