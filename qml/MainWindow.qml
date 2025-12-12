import QtQuick 2.14
import QtQuick.Controls 2.14

ApplicationWindow {
    id: mainWin
    visible: true
    width: 900
    height: 600
    title: "Open Architect UI - Core"

    Rectangle {
        anchors.fill: parent
        color: "#222"

        // Container برای اضافه کردن پلاگین‌ها
        Row {
            id: pluginContainer
            objectName: "pluginContainer"
            spacing: 10
            anchors.centerIn: parent
        }
    }
}
