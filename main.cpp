#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "damier.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    damier damierJeu;
    engine.rootContext()->setContextProperty("damierQML", &damierJeu);
//    if (engine.rootObjects().isEmpty())
//        return -1;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
