#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "audioclass.h"
#include "qqmlcontext.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
	QGuiApplication::setApplicationName("GamAudio");
	QGuiApplication::setOrganizationName("AO RUSPROM");

	AudioClass audio;
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    engine.rootContext()->setContextProperty("audioListDevices", QVariant::fromValue(audio.comboList()));
    engine.rootContext()->setContextProperty("audio", &audio);
    return app.exec();
}
