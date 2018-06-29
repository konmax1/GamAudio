#include "usblnetworkdata.h"

void USBLNetworkData::sendPacket(typeCMD _type){
	QByteArray data;
	data.resize(HEADER_SIZE);
	netHeader *p = (netHeader *)data.data();
	p->data0 = 0;
	p->data1 = 1;
	p->data2 = 2;
	p->data3 = 3;
	p->counter = 2;
	p->type = _type;
	udpsock->write(data);
	udpsock->waitForBytesWritten();
}

void USBLNetworkData::setfreq(quint32 freq){
	QByteArray data;
	data.resize(HEADER_SIZE + 4);
	netHeader *p = (netHeader *)data.data();
	p->data0 = 0;
	p->data1 = 1;
	p->data2 = 2;
	p->data3 = 3;
	p->counter = 2;
	p->type = tSetFreqADC;
	quint32 *p_freq = (quint32*)(data.data() + HEADER_SIZE);
	*p_freq = freq;
	udpsock->write(data);
	udpsock->waitForBytesWritten();
}


void USBLNetworkData::connectToUSBL(QString _ip, quint32 freq, quint32 channel){
	emit connectToUSBLthSig(_ip, freq,channel);
}


void USBLNetworkData::connectToUSBLth(QString _ip, quint32 freq, quint32 channel) {
	if (udpsock->isOpen())
		udpsock->disconnectFromHost();
	udpsock->connectToHost(_ip, 8000);

	SOCKET sock;
	sock = udpsock->socketDescriptor();
	int sizeBuffSet = 4000000;
	int sizeBuffGet;
	int optlen = sizeof(sizeBuffSet);
	setsockopt(sock, SOL_SOCKET, SO_RCVBUF, (char *)&sizeBuffSet, optlen);
	getsockopt(sock, SOL_SOCKET, SO_RCVBUF, (char *)&sizeBuffGet, &optlen);
	channelProc = channel - 1;

	sendPacket(tStopADC);
	sendPacket(tStopQuat);
	QThread::msleep(200);
	udpsock->flush();

	cntPkt = 0;
	sendPacket(tInitConn);
	sendPacket(tLinADC);
	setfreq(freq);
	sendPacket(tStartADC);

    return;
}

void USBLNetworkData::disconnectFromUSBLth()
{
    sendPacket(tStopADC);
    sendPacket(tStopQuat);
    udpsock->disconnectFromHost();
}

void USBLNetworkData::startedThread(){
	udpsock = new QUdpSocket();
	udpsock->bind(QHostAddress::Any, 8000);
	connect(udpsock, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(this,SIGNAL(connectToUSBLthSig(QString,quint32, quint32)),this,SLOT(connectToUSBLth(QString,quint32, quint32)));



	return;
}

USBLNetworkData::USBLNetworkData(QObject *parent)	: QObject(parent){

	datagram.resize(2000);
	channelProc = 0;
	cntPkt = 0;
}

USBLNetworkData::~USBLNetworkData(){


	sendPacket(tStopADC);
	sendPacket(tStopQuat);

}
void USBLNetworkData::readyRead(){
	netBuf* p = (netBuf*)datagram.data();
	int32_t sizes;
	do {
		udpsock->readDatagram(datagram.data(), 5000, &address);
		if (p->header.type == tADCsmpl) {
			for (volatile int i = 0; i < SMPL_CNT; i++) {
				inputdata.append(p->mas[i][channelProc]);
			}
		}
		if (p->header.counter != cntPkt) {
			qDebug() << "Lost Packet" << cntPkt;
			cntPkt = p->header.counter + 1;
		}else
			cntPkt++;
		sizes = udpsock->pendingDatagramSize();
	} while (sizes > 0);
	if (inputdata.size() > 30000) {
		emit addNewDataSig(inputdata);
		inputdata.clear();
	}
}
