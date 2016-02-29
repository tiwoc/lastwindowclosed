import QtQuick.Controls 1.4

ApplicationWindow {
    id: root

    Button {
        text: "close"

        onClicked: {
            console.log("close button clicked")
            root.close()
        }
    }

    onClosing: {
        console.log("onClosing()")
    }
}
