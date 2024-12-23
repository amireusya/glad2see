import QtQuick 2.6
import QtQuick.Controls 2.0
import com.window.main

ApplicationWindow {
    id: root
    width: 640
    height: 480
    visible: true
    title: "glad2see"
    CMainWindow {
        id: mWnd
    }
    TextField {
        
        selectByMouse: true
        text: mWnd.userName
        placeholderText: qsTr("User name")
        anchors.centerIn: parent
        
        onEditingFinished: mWnd.userName = text
    }
}