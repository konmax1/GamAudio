#include "datachart.h"






void dataChart::initSeries(QAbstractSeries * _series, quint32 param)
{
	pointChart.resize(param);
	pointChart.last().resize(lengraph+1);
	param = param - 1;
	for (volatile int j = 0; j < pointChart[param].size(); j++) {
		pointChart[param][j].setX(j);
	}
	ser.resize(param);
    ser.append(_series);

	return;
}

QChart& dataChart::getChart()
{
    return chart;
}

void dataChart::resizeCharts(qint32 _newsize)
{
	lengraph = _newsize;
	for (volatile int i = 0; i < pointChart.size(); i++) {
        pointChart[i].resize(lengraph+1);
		for (volatile int j = 0; j < pointChart[i].size(); j++) {
			pointChart[i][j].setX(j);
		}
	}
}

dataChart::dataChart(QObject *parent)
    : QObject(parent)
{


	lengraph = 300000;

	curpos = 0;
	isActiveChart = false;

	QValueAxis *axisX = new QValueAxis;
	QValueAxis *axisY = new QValueAxis;
	chart.addAxis(axisX, Qt::AlignBottom);
	chart.addAxis(axisY, Qt::AlignLeft);
	axisX->setRange(0, lengraph );
	axisY->setRange(-10000, 10000);
	QLineSeries *series;
	
	series = new QLineSeries();
    for (int i = 0; i < lengraph; i++) {
		series->setName("ADC sh PORd2");
        series->setUseOpenGL(true);
    }
	chart.addSeries(series);
	initSeries(series, 1);
	series->attachAxis(axisX);
	series->attachAxis(axisY);

    series = new QLineSeries();
	for (int i = 0; i < lengraph; i++) {
        series->setName("Image");
        series->setUseOpenGL(true);
	}
	chart.addSeries(series);
	initSeries(series, 2);
	series->attachAxis(axisX);
	series->attachAxis(axisY);

    /*series = new QLineSeries();
	for (int i = 0; i < lengraph; i++) {
        series->setName("ADC");
        series->setUseOpenGL(true);
	}
	chart.addSeries(series);
	initSeries(series, 3);
	series->attachAxis(axisX);
	series->attachAxis(axisY);*/

    chart.setTitle("USBL charts");
    chart.setAnimationOptions(QChart::SeriesAnimations);
    chart.legend()->show();

    //chart.createDefaultAxes();


}

dataChart::~dataChart()
{
}

void dataChart::sendChartData(QVector<double> _v1, QVector<double> _v2){

	QXYSeries *xySeries;
	for (volatile int k = 0; k < ser.size() ; k++)
	{
		xySeries = static_cast<QXYSeries *>(ser[k]);
		for (volatile int i = 0; i < _v1.size(); i++) {
			if (k == 0)
				pointChart[k][curpos].setY((double)_v1[i]);
			else
				pointChart[k][curpos].setY((double)_v2[i]);
			curpos = (curpos + 1) % lengraph;
		}
		xySeries->replace(pointChart[k]);
	}
}

void dataChart::destruct(QAbstractSeries * _series)
{
	pointChart.clear();
    ser.clear();
}

void dataChart::setActive(bool _act, qint32 _len)
{
	isActiveChart = _act;
	if (isActiveChart)
		resizeCharts(_len);

}


void dataChart::sendChartData(QList< QVector<double> > _v) {
	if (!isActiveChart)
		return;
	QXYSeries *xySeries;
	for (volatile int k = 0; k < ser.size(); k++)
	{
		xySeries = static_cast<QXYSeries *>(ser[k]);
		for (volatile int i = 0; i < _v[k].size(); i++) {
			pointChart[k][curpos].setY((double)_v[k][i]);
			curpos = (curpos + 1) % lengraph;
		}
		xySeries->replace(pointChart[k]);
	}
}






