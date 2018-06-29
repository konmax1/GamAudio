#pragma once

#include <QObject>

#include <QDataStream>
#include <QUdpSocket>
#include <winsock2.h>

#include "recieverdata.h"
#include <qthread.h>


#define HEADER_SIZE (12)
#define SMPL_CNT (90)

enum typeCMD : uint16_t {
	tInitConn = 0x0001,
	tStartADC = 0x0002,
	tStopADC = 0x0003,
	tSetFreqADC = 0x0004,
	tADCsmpl = 0x0005,
	tSetOuter = 0x0006,
	tADCsmplOuter = 0x0007,
	tLogADC = 0x0010,
	tLinADC = 0x0011,
	tOffADC = 0x0012,
	tStartQuat = 0x0020,
	tStopQuat = 0x0021,
	tQuatsmpl = 0x0022,
	tQuatSave = 0x0023,
	tErr = 0x00FF,
	tUnknown = 0xFFFF,
};

struct netHeader {
	typeCMD type;
	uint16_t counter;
	uint16_t data0;
	uint16_t data1;
	uint16_t data2;
	uint16_t data3;
};

struct netBuf {
	netHeader header;
	int16_t mas[SMPL_CNT][8];
};

Q_DECLARE_METATYPE(QVector<double>)
class USBLNetworkData : public QObject
{
	Q_OBJECT

private:
	QUdpSocket * udpsock;
	void sendPacket(typeCMD _type);
	void setfreq(quint32 freq);
	int32_t channelProc;
	QByteArray datagram;
	QHostAddress address;
	quint16 cntPkt;
	QVector<double> inputdata;
public:
	Q_INVOKABLE void connectToUSBL(QString _ip, quint32 freq, quint32 channel = 1);
	USBLNetworkData(QObject *parent = 0);
	~USBLNetworkData();
signals:
	void connectToUSBLthSig(QString _ip, quint32 freq, quint32 channel = 1);
	void addNewDataSig(QVector<double> _vec);
public slots:
	void connectToUSBLth(QString _ip, quint32 freq, quint32 channel = 1);
    void disconnectFromUSBLth();
	void startedThread();
	void readyRead();
};
