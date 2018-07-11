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

struct freqVal{
	uint32_t count_freq = 0;
	complex_double signal_freq;
	double freqWave;
    std::vector<complex_double> delayLine;
};

struct debugDataFile {
	double adc;
	double analitRe;
	double analitIm;

};

class RecieverData : public QObject
{
	Q_OBJECT
private:
	quint32 freqDiskr;
	QVector<freqVal> freqval;
    qint32 freqSignal;
	int32_t counterThinning;

	QVector<double> thinningSignal;
	QVector<debugDataFile> debugFileData;
private: //functions
	void getWave(int channel);
	void complexMult(complex_double & _in, complex_double & _in2, complex_double & _out);
	complex_double complexMult(complex_double & _in);
	complex_double complexSum(std::vector<complex_double>& _vect);
	double complexAbs(complex_double &_cmplx);
public:
    RecieverData(QObject *parent = nullptr);
	~RecieverData();
	std::vector<double> delayLine;
	//uint32_t 
	quint32 getFreqDiskr() ;
    void setFreqDiskr(quint32 value);
	void clearDebugData();
	
	QVector<debugDataFile>& getDataToWrite();
    void setFreqSignal(const qint32 &value);

public slots:
    void addNewData(QVector<double> _vec);
    double Gilbert(double &sample);
signals:
	void sendChartData(QVector<double> _v1, QVector<double> _v2);
	void sendChartData(QList< QVector<double> > _v);
};

extern RecieverData recData;
