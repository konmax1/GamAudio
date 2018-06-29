#include <QApplication>

#include <QMetaType>

#include "mainwindow.h"



//#include <QtWidgets/QApplication>
//#include <QQmlApplicationEngine>
//#include "audioclass.h"
//#include "qqmlcontext.h"
//#include "datachart.h"
//#include "usblnetworkdata.h"
//#include <QThreadPool>
//#include "recieverdata.h"
//#include <QMetaType>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);
    QApplication::setApplicationName("GamAudio");
    QApplication::setOrganizationName("AO RUSPROM");


	int id = qRegisterMetaType<QVector<double> >("QVector<double>");

	id = qRegisterMetaType<	QList<QVector<double> > >("QList<QVector<double> >");


    //QQmlApplicationEngine engine;


    MainWindow window;
	window.grabGesture(Qt::PanGesture);
	window.grabGesture(Qt::PinchGesture);
    window.show();
    //engine.rootContext()->setContextProperty("audio", &window.audio);
    //engine.rootContext()->setContextProperty("chartV", &window.chartV);
    //engine.rootContext()->setContextProperty("networkData", &window.networkData);

    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //if (engine.rootObjects().isEmpty())
    //    return -1;

    return app.exec();
}

















