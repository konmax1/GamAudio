#pragma once

#include <QObject>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QStringListModel>
#include <QStringList>
#include <QAudioOutput>

class AudioClassUSBL : public QObject
{
	Q_OBJECT
private:

	QAudioDeviceInfo m_device;
	QAudioFormat m_format;
	QAudioOutput *m_audioOutput;
	QIODevice *m_output; // not owned
    bool isActiveAudio;
	double freqAudioDiskr;

	void reInitAudioDev();
public:
    AudioClassUSBL();
    AudioClassUSBL(QObject *parent );
    ~AudioClassUSBL();

    QStringListModel audioListDevices;


	bool getIsActiveAudio();
    void setIsActiveAudio(bool &value);

public slots:
    void WriteAudioData(quint16 nADC, quint16 *mas);
	void setActiveAudio(bool _active, qint32 _freqD);
};
