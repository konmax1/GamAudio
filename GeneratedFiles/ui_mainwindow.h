/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <MainWindow.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QLineEdit *lineEditIP;
    QLabel *labelIP;
    QLabel *labelADC;
    QSpinBox *spinBoxADC;
    QSpinBox *spinBoxFreq;
    QLabel *labelFreq;
    QPushButton *pushButtonStartADC;
    QPushButton *pushButtonStopADC;
    QGroupBox *groupBox_2;
    QCheckBox *checkBoxCharts;
    QCheckBox *checkBox_Audio;
    QSpinBox *spinBoxLenCharts;
    QSpinBox *spinBoxFreqAudio;
    ChartView *charts_templ;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(824, 612);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(300, 200));
        groupBox->setMaximumSize(QSize(300, 16777215));
        lineEditIP = new QLineEdit(groupBox);
        lineEditIP->setObjectName(QStringLiteral("lineEditIP"));
        lineEditIP->setGeometry(QRect(140, 40, 141, 31));
        lineEditIP->setFrame(false);
        lineEditIP->setEchoMode(QLineEdit::Normal);
        lineEditIP->setCursorPosition(15);
        lineEditIP->setAlignment(Qt::AlignCenter);
        labelIP = new QLabel(groupBox);
        labelIP->setObjectName(QStringLiteral("labelIP"));
        labelIP->setGeometry(QRect(20, 40, 121, 31));
        labelADC = new QLabel(groupBox);
        labelADC->setObjectName(QStringLiteral("labelADC"));
        labelADC->setGeometry(QRect(20, 80, 121, 31));
        spinBoxADC = new QSpinBox(groupBox);
        spinBoxADC->setObjectName(QStringLiteral("spinBoxADC"));
        spinBoxADC->setGeometry(QRect(140, 80, 141, 31));
        spinBoxADC->setAlignment(Qt::AlignCenter);
        spinBoxADC->setMinimum(1);
        spinBoxADC->setMaximum(8);
        spinBoxFreq = new QSpinBox(groupBox);
        spinBoxFreq->setObjectName(QStringLiteral("spinBoxFreq"));
        spinBoxFreq->setGeometry(QRect(140, 120, 141, 31));
        spinBoxFreq->setAlignment(Qt::AlignCenter);
        spinBoxFreq->setMinimum(1);
        spinBoxFreq->setMaximum(500000);
        spinBoxFreq->setSingleStep(1000);
        spinBoxFreq->setValue(300000);
        labelFreq = new QLabel(groupBox);
        labelFreq->setObjectName(QStringLiteral("labelFreq"));
        labelFreq->setGeometry(QRect(20, 120, 121, 31));
        pushButtonStartADC = new QPushButton(groupBox);
        pushButtonStartADC->setObjectName(QStringLiteral("pushButtonStartADC"));
        pushButtonStartADC->setGeometry(QRect(20, 160, 121, 31));
        pushButtonStopADC = new QPushButton(groupBox);
        pushButtonStopADC->setObjectName(QStringLiteral("pushButtonStopADC"));
        pushButtonStopADC->setGeometry(QRect(160, 160, 121, 31));

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(300, 200));
        checkBoxCharts = new QCheckBox(groupBox_2);
        checkBoxCharts->setObjectName(QStringLiteral("checkBoxCharts"));
        checkBoxCharts->setGeometry(QRect(20, 30, 171, 31));
        checkBox_Audio = new QCheckBox(groupBox_2);
        checkBox_Audio->setObjectName(QStringLiteral("checkBox_Audio"));
        checkBox_Audio->setGeometry(QRect(20, 70, 131, 31));
        spinBoxLenCharts = new QSpinBox(groupBox_2);
        spinBoxLenCharts->setObjectName(QStringLiteral("spinBoxLenCharts"));
        spinBoxLenCharts->setGeometry(QRect(200, 31, 91, 31));
        spinBoxLenCharts->setMinimum(1);
        spinBoxLenCharts->setMaximum(1000000);
        spinBoxLenCharts->setSingleStep(10000);
        spinBoxLenCharts->setValue(300000);
        spinBoxLenCharts->setDisplayIntegerBase(10);
        spinBoxFreqAudio = new QSpinBox(groupBox_2);
        spinBoxFreqAudio->setObjectName(QStringLiteral("spinBoxFreqAudio"));
        spinBoxFreqAudio->setGeometry(QRect(200, 70, 91, 31));
        spinBoxFreqAudio->setMinimum(1);
        spinBoxFreqAudio->setMaximum(200000);
        spinBoxFreqAudio->setSingleStep(1000);
        spinBoxFreqAudio->setValue(9600);
        spinBoxFreqAudio->setDisplayIntegerBase(10);

        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        charts_templ = new ChartView(centralwidget);
        charts_templ->setObjectName(QStringLiteral("charts_templ"));
        charts_templ->setMinimumSize(QSize(500, 400));
        charts_templ->setFrameShape(QFrame::NoFrame);
        charts_templ->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(charts_templ, 0, 1, 2, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 824, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \321\201\320\265\321\202\320\270", nullptr));
        lineEditIP->setInputMask(QApplication::translate("MainWindow", "000.000.000.000", nullptr));
        lineEditIP->setText(QApplication::translate("MainWindow", "192.168.30.170", nullptr));
        labelIP->setText(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201", nullptr));
        labelADC->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 \320\220\320\246\320\237", nullptr));
        labelFreq->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260 \320\220\320\246\320\237", nullptr));
        pushButtonStartADC->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        pushButtonStopADC->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
        checkBoxCharts->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \320\263\321\200\320\260\321\204\320\270\320\272\320\260", nullptr));
        checkBox_Audio->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264 \320\267\320\262\321\203\320\272\320\260", nullptr));
        spinBoxLenCharts->setSuffix(QString());
        spinBoxLenCharts->setPrefix(QString());
        spinBoxFreqAudio->setSuffix(QString());
        spinBoxFreqAudio->setPrefix(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
