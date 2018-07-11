#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "audioclass.h"
#include "usblnetworkdata.h"
#include <QThreadPool>
#include "recieverdata.h"
#include "qfile.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    AudioClassUSBL audio;
    RecieverData recData;
    USBLNetworkData networkData;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonStartADC_clicked();
	
    void on_checkBox_Audio_stateChanged(int arg1);

    void on_spinBoxFreqSignal_valueChanged(int arg1);

    void on_pushButtonFileClear_clicked();

    void on_pushButtonFileWrite_clicked();

private:
	Ui::MainWindow *ui;
    QThread threadPckts;
    QThread threadProcdata;
};

#endif // MAINWINDOW_H
