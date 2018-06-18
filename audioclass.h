#pragma once

#include <QObject>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QStringListModel>
#include <QStringList>
#include <QAudioOutput>

class AudioClass : public QObject
{
	Q_OBJECT

    Q_PROPERTY(QStringList comboList READ comboList WRITE setComboList NOTIFY comboListChanged)
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
private:
    QStringList m_comboList;
    int         m_count;

	QAudioOutput *m_audioOutput;
	QIODevice *m_output; // not owned

public:
	AudioClass();
	AudioClass(QObject *parent );
	~AudioClass();

    QStringListModel audioListDevices;
    const QStringList comboList();
    void setComboList(const QStringList &comboList);
    int count();
    void setCount(int cnt);
    Q_INVOKABLE void addElement(const QString &element);
    Q_INVOKABLE void removeElement(int index);
    Q_INVOKABLE void clearAudioList();

public slots:
	void createAudioList();
	void setAudioOutputDevice(QString dev);
signals:
    void comboListChanged();
    void countChanged();
};
