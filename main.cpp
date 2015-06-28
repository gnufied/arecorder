#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "arecorder.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<ARecorder>("com.codemancers.components", 1, 0, "ARecorder");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
