import QtQuick 2.4

ViForm {
    Rectangle
    {
        anchors.fill: parent
        color: Qt.rgba(230/255, 207/255, 213/255, 1)
        Text
        {
            id: text
            anchors.centerIn: parent
            font.pixelSize: 48
            font.italic: true
            color: Qt.rgba(255/255, 215/255, 0, 1)
            text: "ikun"
        }
        ShaderEffect
        {
            id: shaderEffect
            anchors.centerIn: parent
            width: text.implicitWidth
            height: text.implicitHeight
            property real divider: 0
            property real gradient: 0.2
            property variant source: shaderSource
            ShaderEffectSource
            {
                id: shaderSource
                sourceItem: text
                hideSource: true
            }
        }
    }
}
