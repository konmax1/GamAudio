#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "audioclass.h"
#include "datachart.h"
#include "usblnetworkdata.h"
#include <QThreadPool>
#include "recieverdata.h"

namespace Ui {
class MainWindow;
}

class ChartView : public QChartView
//![1]
{
public:
    ChartView(QWidget *parent = 0);

//![2]
protected:
    bool viewportEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
//![2]

private:
    bool m_isTouching;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    AudioClassUSBL audio;
    dataChart chartV;
    RecieverData recData;
    USBLNetworkData networkData;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonStartADC_clicked();

    void on_checkBoxCharts_stateChanged(int arg1);

    void on_checkBox_Audio_stateChanged(int arg1);

private:


    ChartView *charts;
    Ui::MainWindow *ui;
    QThread threadPckts;
	QThread threadCharts;
};

#endif // MAINWINDOW_H
