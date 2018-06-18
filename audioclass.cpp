#include "audioclass.h"
#include "qdebug.h"

AudioClass::AudioClass(QObject *parent )
	: QObject(parent)
{

	m_audioOutput = new QAudioOutput(m_device, m_format, this);
}

AudioClass::AudioClass(){
}

AudioClass::~AudioClass()
{
}

void AudioClass::createAudioList() {
	qDebug() << "Create List ";
    clearAudioList();
	for (QAudioDeviceInfo &deviceInfo : QAudioDeviceInfo::availableDevices(QAudio::AudioOutput)) {
        addElement(deviceInfo.deviceName());
    }


}

int AudioClass::count()
{
    return m_count;
}

void AudioClass::setCount(int cnt)
{
    if (cnt != m_count)
    {
        m_count = cnt;
        emit countChanged();
    }
}

const QStringList AudioClass::comboList()
{
    return m_comboList;
}

void AudioClass::setComboList(const QStringList &comboList)
{

    if (m_comboList != comboList)
    {
        m_comboList = comboList;
        emit comboListChanged();
    }

}

void AudioClass::addElement(const QString &element)
{
    m_comboList.append(element);
    emit comboListChanged();
    setCount(m_comboList.count());
    emit countChanged();
}

void AudioClass::removeElement(int index)
{
    if (index < m_comboList.count())
    {
        m_comboList.removeAt(index);
        emit comboListChanged();
        setCount(m_comboList.count());
        emit countChanged();
    }
}

void AudioClass::clearAudioList()
{
    m_comboList.clear();
    emit comboListChanged();
    setCount(m_comboList.count());
    emit countChanged();
}

void AudioClass::setAudioOutputDevice(QString dev)
{
	if (dev == "")
		return;
	qDebug() << "Current Audio = " << dev ;
	QAudioDeviceInfo m_device;
	for (QAudioDeviceInfo &deviceInfo : QAudioDeviceInfo::availableDevices(QAudio::AudioOutput)) {
		if (deviceInfo.deviceName == dev) {
			m_device = deviceInfo;
			break;
		}
	}
	QAudioFormat format;
	format.setSampleRate(44100);
	format.setChannelCount(1);
	format.setSampleSize(16);
	format.setCodec("audio/pcm");
	format.setByteOrder(QAudioFormat::LittleEndian);
	format.setSampleType(QAudioFormat::SignedInt);
	delete m_audioOutput;
	m_audioOutput = new QAudioOutput(m_device, format, this);
	m_audioOutput->setBufferSize(56000);
}













