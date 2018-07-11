#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QLineSeries"
#include "qdebug.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	
    threadPckts.setObjectName("UDP_thread");
    networkData.moveToThread(&threadPckts);
    QObject::connect(&threadPckts, SIGNAL(started()), &networkData, SLOT(startedThread()));
    threadPckts.start(QThread::TimeCriticalPriority);

    threadProcdata.setObjectName("Proc_thread");
    recData.moveToThread(&threadProcdata);
    //QObject::connect(&threadProcdata, SIGNAL(started()), &threadProcdata, SLOT(startedThread()));
    threadProcdata.start(QThread::TimeCriticalPriority);

    QObject::connect(&networkData,SIGNAL(addNewDataSig(QVector<double>)),&recData,SLOT(addNewData(QVector<double>)));
    QObject::connect(ui->pushButtonStopADC,SIGNAL(clicked(bool)),&networkData,SLOT(disconnectFromUSBLth()));


}

MainWindow::~MainWindow(){
	threadPckts.terminate();
    threadProcdata.terminate();
	//networkData.disconnectFromUSBLth();
    delete ui;
}

void MainWindow::on_pushButtonStartADC_clicked()
{
    networkData.connectToUSBL(ui->lineEditIP->text(),ui->spinBoxFreq->value(),ui->spinBoxADC->value());
    recData.setFreqDiskr(ui->spinBoxFreq->value());

}

void MainWindow::on_checkBox_Audio_stateChanged(int arg1)
{
    audio.setActiveAudio(arg1, ui->spinBoxFreqAudio->value());
}

void MainWindow::on_spinBoxFreqSignal_valueChanged(int arg1)
{
    recData.setFreqSignal(arg1);
}

void MainWindow::on_pushButtonFileClear_clicked()
{
	recData.clearDebugData();
}

void MainWindow::on_pushButtonFileWrite_clicked()
{
	QFile file("debugData.ini");
	qDebug() << file.open(QIODevice::WriteOnly);
	QTextStream out(&file);
	QVector<debugDataFile> * p = &recData.getDataToWrite();
	out << "ADC" << "\t" << "AnalitRe" << "\t" <<"AnalitIm" << "\t" << endl;
	for (volatile int i = 0; i < p->size(); i++) {
		out << p->at(i).adc << "\t" << p->at(i).analitRe << "\t" << p->at(i).analitIm << "\t" << endl;
	}
	file.close();
	qDebug() << "File Write" <<endl;
}
