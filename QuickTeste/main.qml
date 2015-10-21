import QtQuick 2.3
import QtQuick.Window 2.2
import QtGStreamer 1.0

Window {
    visible: true
    width: 640
    height: 480

    MouseArea {
        anchors.fill: parent
        onClicked: {
            text1.visible = false;            
            player.play();
            text2.visible = true;
        }
    }

    VideoItem {
        id: video
        width: 640
        height: 480
        surface: videoSurface1

        Text {
            id: text1
            x: 193
            y: 207
            width: 254
            height: 66
            color: "#ffffff"
            text: qsTr("Click to Start")
            font.pixelSize: 42
        }

        Text {
            id: text2
            x: 215
            y: 388
            width: 211
            height: 84
            color: "#ffffff"
            text: qsTr("Playing..\nClick to Restart")
            font.pixelSize: 31
            visible: false
        } //bound on the context from main()

    }

}
