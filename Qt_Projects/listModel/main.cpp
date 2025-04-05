#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "mylistmodel.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    MyListModel myModel;
    engine.rootContext()->setContextProperty("mymodel", &myModel);
    engine.loadFromModule("listModel", "Main");

    return app.exec();
}
