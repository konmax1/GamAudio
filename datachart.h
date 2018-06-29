#pragma once

#include <QObject>
#include <QtCharts/QAbstractSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QRubberBand>
#include <QtCharts/QXYSeries>
#include <QtCharts/QAreaSeries>
#include <QtCore/QRandomGenerator>
#include <QtCore/QtMath>

#include <QValueAxis>
#include <QSplineSeries>

QT_CHARTS_USE_NAMESPACE


Q_DECLARE_METATYPE(QList<QVector<double> >)

class dataChart : public QObject
{
	Q_OBJECT
private:
	QVector<QAbstractSeries*> ser;
	QVector< QVector<QPointF> >pointChart;
	qint32 curpos;
	qint32 lengraph;
    QChart chart;
    bool isActiveChart;

	void resizeCharts(qint32 _newsize);
public:

	dataChart(QObject *parent = 0);
	~dataChart();


    QChart &getChart() ;

public slots:
    void initSeries(QAbstractSeries* _series, quint32 param);
	void sendChartData(QVector<double> _v1, QVector<double> _v2);
	void sendChartData(QList< QVector<double> > _v);
	void destruct(QAbstractSeries * _series);
    void setActive(bool _act, qint32 _len);

};
