#pragma once

#include <QObject>
#include <qvector.h>


#include <qmath.h>  

#define GILBERT_POR     100                      // порядок фильтра
#define GILBERT_POR2    GILBERT_POR/2           // половина от порядка фильтра

struct complex_double{
	double re;
	double im;
};

class RecieverData : public QObject
{
	Q_OBJECT
private:
	uint32_t countFreq;
	quint32 freqDiskr;
public:
	RecieverData(QObject *parent = 0);
	~RecieverData();
	std::vector<double> delayLine;
	//uint32_t 
	quint32 getFreqDiskr() ;
    void setFreqDiskr(quint32 value);

public slots:
    void addNewData(QVector<double> _vec);
    double Gilbert(double &sample);
	complex_double complexMult(double &re, double &im);
signals:
	void sendChartData(QVector<double> _v1, QVector<double> _v2);
	void sendChartData(QList< QVector<double> > _v);
};

extern RecieverData recData;
