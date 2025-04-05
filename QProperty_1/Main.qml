import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Text {
        width:100
        height: 50
        x: 20
        y:20
        id: t
        text: mymodel.count
        color: "red"
        Component.onCompleted:
        {
            //if this line run then after thistext will not be updated using AbstractListModel
            //same way text = 5 also. text: mymodel.count will not work
            t.text = mymodel.count;
        }
    }
    Button
    {
        width:100
        height: 50
        anchors.centerIn: parent
        text:  "click me"
        onClicked: {
            mymodel.count =  (mymodel.count + 1)
            mymodel.change()
            t.color = "black"

        }
    }
}
