#include "audioclass.h"
#include "qdebug.h"

AudioClassUSBL::AudioClassUSBL(QObject *parent )
	: QObject(parent)
{
    AudioClassUSBL();

}

bool AudioClassUSBL::getIsActiveAudio()
{
    return isActiveAudio;
}

void AudioClassUSBL::setIsActiveAudio(bool &value)
{
    isActiveAudio = value;
}

void AudioClassUSBL::reInitAudioDev()
{
	if (m_audioOutput) {
		m_audioOutput->stop();
		delete m_audioOutput;

	}


	m_format.setSampleRate(freqAudioDiskr);
	m_format.setChannelCount(1);
	m_format.setSampleSize(16);
	m_format.setCodec("audio/pcm");
	m_format.setByteOrder(QAudioFormat::LittleEndian);
	m_format.setSampleType(QAudioFormat::SignedInt);

	m_device = QAudioDeviceInfo::defaultOutputDevice();
	m_audioOutput = new QAudioOutput(m_device, m_format, this);
	m_audioOutput->setBufferSize(56000);
	m_output = m_audioOutput->start();
}

AudioClassUSBL::AudioClassUSBL(){

	m_audioOutput = nullptr;
	freqAudioDiskr = 9600;
	reInitAudioDev();

}


void AudioClassUSBL::setActiveAudio(bool _active, qint32 _freqD)
{
	isActiveAudio = _active;
	freqAudioDiskr = _freqD;
	if (isActiveAudio)
		reInitAudioDev();

}


AudioClassUSBL::~AudioClassUSBL()
{
}


void AudioClassUSBL::WriteAudioData(quint16 nADC, quint16 *mas)
{
	if (m_audioOutput && m_audioOutput->state() != QAudio::StoppedState) {
		m_output->write((const char *)mas, 2 * nADC);
	}
}










