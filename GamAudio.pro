QT += network multimedia  widgets core gui charts qml
CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


win32|win64{
LIBS+= -lws2_32
}


SOURCES += \
        main.cpp \
    audioclass.cpp \
    usblnetworkdata.cpp \
    recieverdata.cpp \
    mainwindow.cpp

RESOURCES +=


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



HEADERS += \
    audioclass.h \
    usblnetworkdata.h \
    recieverdata.h \
    mainwindow.h

FORMS += \
    mainwindow.ui
