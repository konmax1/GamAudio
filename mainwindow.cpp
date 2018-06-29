#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QLineSeries"
#include "qdebug.h"



ChartView::ChartView(QWidget *parent) :
    m_isTouching(false),
	QChartView(parent)
{
    setRubberBand(QChartView::RectangleRubberBand);
}

bool ChartView::viewportEvent(QEvent *event)
{
    if (event->type() == QEvent::TouchBegin) {
        // By default touch events are converted to mouse events. So
        // after this event we will get a mouse event also but we want
        // to handle touch events as gestures only. So we need this safeguard
        // to block mouse events that are actually generated from touch.
        m_isTouching = true;

        // Turn off animations when handling gestures they
        // will only slow us down.
        chart()->setAnimationOptions(QChart::NoAnimation);
    }
    return QChartView::viewportEvent(event);
}

void ChartView::mousePressEvent(QMouseEvent *event)
{
    if (m_isTouching)
        return;
    QChartView::mousePressEvent(event);
}

void ChartView::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isTouching)
        return;
    QChartView::mouseMoveEvent(event);
}

void ChartView::mouseReleaseEvent(QMouseEvent *event)
{
    if (m_isTouching)
        m_isTouching = false;

    // Because we disabled animations when touch event was detected
    // we must put them back on.
    chart()->setAnimationOptions(QChart::SeriesAnimations);

    QChartView::mouseReleaseEvent(event);
}

//![1]
void ChartView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
	case Qt::Key_Slash:
		chart()->zoomReset();
		break;
    case Qt::Key_Plus:
        chart()->zoomIn();
        break;
    case Qt::Key_Minus:
        chart()->zoomOut();
        break;
//![1]
    case Qt::Key_Left:
        chart()->scroll(-10, 0);
        break;
    case Qt::Key_Right:
        chart()->scroll(10, 0);
        break;
    case Qt::Key_Up:
        chart()->scroll(0, 10);
        break;
    case Qt::Key_Down:
        chart()->scroll(0, -10);
        break;
    default:
        QGraphicsView::keyPressEvent(event);
        break;
    }
}









MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	
    ui->charts_templ->setChart(&chartV.getChart());
    ui->charts_templ->setRenderHint(QPainter::Antialiasing);


    threadPckts.setObjectName("UDP_thread");
    networkData.moveToThread(&threadPckts);
    QObject::connect(&threadPckts, SIGNAL(started()), &networkData, SLOT(startedThread()));
    threadPckts.start(QThread::TimeCriticalPriority);

	threadCharts.setObjectName("Charts_thread");
	chartV.moveToThread(&threadCharts);
	//QObject::connect(&threadPckts, SIGNAL(started()), &networkData, SLOT(startedThread()));
	threadCharts.start(QThread::TimeCriticalPriority);


    QObject::connect(&networkData,SIGNAL(addNewDataSig(QVector<double>)),&recData,SLOT(addNewData(QVector<double>)));
    QObject::connect(&recData,SIGNAL(sendChartData(QVector<double>,QVector<double>)),&chartV,SLOT(sendChartData(QVector<double>,QVector<double>)));
    QObject::connect(ui->pushButtonStopADC,SIGNAL(clicked(bool)),&networkData,SLOT(disconnectFromUSBLth()));

	QObject::connect(&recData, SIGNAL(sendChartData(QList< QVector<double> >)), &chartV, SLOT(sendChartData(QList< QVector<double> >)));

}

MainWindow::~MainWindow(){
	threadPckts.terminate();
	//networkData.disconnectFromUSBLth();
    delete ui;
}

void MainWindow::on_pushButtonStartADC_clicked()
{
    networkData.connectToUSBL(ui->lineEditIP->text(),ui->spinBoxFreq->value(),ui->spinBoxADC->value());
	recData.setFreqDiskr(ui->spinBoxFreq->value());

}

void MainWindow::on_checkBoxCharts_stateChanged(int arg1)
{
    chartV.setActive(arg1,ui->spinBoxLenCharts->value());
}


void MainWindow::on_checkBox_Audio_stateChanged(int arg1)
{
    audio.setActiveAudio(arg1, ui->spinBoxFreqAudio->value());
}
