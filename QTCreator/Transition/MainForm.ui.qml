import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Item {
    id: item1
    width: 640
    height: 480
    property alias mouseArea1: mouseArea1
    property alias mouseArea2: mouseArea2
    property alias mouseArea3: mouseArea3
    property alias bottomLeftRect: bottomLeftRect
    property alias middleRightRect: middleRightRect
    property alias topLeftRect: topLeftRect
    property alias icon: icon

    Image {
        id: icon
        x: 10
        y: 20
        width: 55
        height: 41
        source: "../Qt5.8.0/Examples/Qt-5.8/quickcontrols2/texteditor/images/qt-logo.png"
    }

    Rectangle {
        id: topLeftRect
        width: 55
        height: 41
        color: "#00000000"
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 20
        border.color: "#808080"

        MouseArea {
            id: mouseArea1
            anchors.fill: parent
        }
    }

    Rectangle {
        id: middleRightRect
        x: -8
        y: 6
        width: 55
        height: 41
        color: "#00000000"
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        MouseArea {
            id: mouseArea2
            anchors.fill: parent
        }
        border.width: 1
        border.color: "#808080"
    }

    Rectangle {
        id: bottomLeftRect
        y: -2
        width: 55
        height: 41
        color: "#00000000"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 10
        MouseArea {
            id: mouseArea3
            anchors.fill: parent
        }
        border.width: 1
        border.color: "#808080"
    }
}
