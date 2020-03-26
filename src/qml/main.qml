import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Window 2.14

ApplicationWindow {
    id: root
    width: Math.round(0.8 * Screen.width)
    height: Math.round(0.8 * Screen.height)
    visible: true

    function reload() {
        console.log("reloading...")
        shim.source = ""
        $App.clearComponentCache();
        shim.source = "app.qml"
    }

    Connections {
        target: $App
        onReload: root.reload()
    }

    Loader {
        id: shim
        anchors.fill: parent
        source: "app.qml"
    }
}
