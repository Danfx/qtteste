#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "player.h"

#include <Qt5GStreamer/QGst/Init>
//#include <QGst/Init>



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QGst::init(&argc, &argv);

    QQmlApplicationEngine engine;
    QQmlContext* ctx = engine.rootContext();

    Player pl(ctx);
    ctx->setContextProperty(QLatin1String("player"), &pl);
    ctx->setContextProperty(QLatin1String("videoSurface1"), NULL);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
