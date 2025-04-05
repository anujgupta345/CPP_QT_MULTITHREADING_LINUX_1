import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Controls 2.15
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    TableView
    {
        implicitHeight: 640
        implicitWidth: 480
        anchors.fill: parent
            columnSpacing: 1
            rowSpacing: 1
            clip: true
        model: myModel

        delegate:
        Rectangle
        {
            id:r
            height: 50;
            width:100
            border.color: "black"

            Text {
                anchors.centerIn: parent
                id: h
                text: model.newRole
                color: "blue"
                onTextChanged:
                {
                    r.color = "green"
                }
            }
            Text {
                anchors.centerIn: parent
                id: t
                text: model.display
                onTextChanged:
                {
                    r.color = "grey"
                }
            }

        }

    }
}
