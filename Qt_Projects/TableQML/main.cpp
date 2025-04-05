#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <MyTableModel.h>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/tableqml/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    MyTableModel myTableModel;
    engine.rootContext()->setContextProperty("myModel", &myTableModel);
    engine.load(url);

    return app.exec();
}
