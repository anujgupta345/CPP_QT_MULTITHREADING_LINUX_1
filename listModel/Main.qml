import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    ListView
    {
        anchors.fill: parent
        model: mymodel
id: listView

        delegate:
        Item{width :100;
            height:50
                    Row
                    {
                        Text
                        {
                            text: model.textRole
                        }
                        Image
                        {
                            source: model.imageRole
                        }

                    }


        }

    }
}
