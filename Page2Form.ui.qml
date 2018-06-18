import QtQuick 2.11
import QtQuick.Controls 2.4

Page {
    width: 600
    height: 400

    header: Label {
        text: qsTr("Настройки звука")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    ComboBox {
        id: audioDevices
        x: 19
        y: 11
        model: audio.comboList
        width: 549
        height: 33
        textRole: ""
    }

    Connections {
        target: audioDevices
        onEditTextChanged: audio.setAudioOutputDevice(audioDevices.currentText)
    }
}
