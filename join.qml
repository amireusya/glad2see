import QtQuick 2.6
import QtQuick.Controls 2.0
import com.window.join

ApplicationWindow {
    id: root
    width: 400
    height: 200
    visible: true
    title: "glad2see"
    CJoinWindow {
        id: cJwnd
    }
    TextField {
        
        selectByMouse: true
        text: jWnd.userName
        placeholderText: qsTr("User name")
        anchors.centerIn: parent
        
        onEditingFinished: jWnd.userName = text
    }
}