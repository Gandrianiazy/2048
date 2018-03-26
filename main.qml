import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: principaleWindow
    visible: true
    width: 320
    height: 568
    title: qsTr("2048")

    Rectangle {
        id: principaleRectangle
        color: "#faf8ef"
        anchors.fill: parent
        focus: true
        Keys.onPressed: {
            switch (event.key){
            case Qt.Key_Up:
                damierQML.changeCasesUp()
                break
            case Qt.Key_Down:
                damierQML.changeCasesDown()
                break
            case Qt.Key_Right:
                damierQML.changeCasesRight()
                break
            case Qt.Key_Left:
                damierQML.changeCasesLeft()
                break
            case Qt.Key_N:
                damierQML.resetDamier()
                break
            }
        }
        Text {
            id: titre
            y: 20
            width: 150
            height: 50
            color: "#776e65"
            text: qsTr("2048")
            anchors.left: parent.left
            anchors.leftMargin: 20
            font.bold: true
            topPadding: 0
            font.family: "Verdana"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 40
        }

        Rectangle {
            id: scoreRectangle
            x: 190
            y: 20
            width: 50
            height: 50
            color: "#bbada0"
            radius: 10
            anchors.right: parent.right
            anchors.rightMargin: 80
            border.width: 0

            Text {
                id: scoreText
                x: 0
                width: 50
                height: 20
                color: "#eee4da"
                text: qsTr("Score")
                topPadding: 2
                font.bold: true
                font.family: "Verdana"
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 0
                font.pixelSize: 13
            }

            Text {
                id: scoreValText
                x: 0
                y: 20
                width: 50
                height: 30
                color: "#ffffff"
                text: damierQML.scoreQML
                bottomPadding: 5
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.family: "Verdana"
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 12
            }
        }

        Rectangle {
            id: bestRectangle
            x: 246
            y: 20
            width: 50
            height: 50
            color: "#bbada0"
            radius: 10
            anchors.right: parent.right
            anchors.rightMargin: 20
            border.width: 0

            Text {
                id: bestText
                x: 0
                width: 50
                height: 20
                color: "#eee4da"
                text: qsTr("Best")
                font.pixelSize: 13
                horizontalAlignment: Text.AlignHCenter
                font.family: "Verdana"
                anchors.top: parent.top
                font.bold: true
                anchors.topMargin: 0
                anchors.horizontalCenter: parent.horizontalCenter
                topPadding: 2
            }

            Text {
                id: bestValText
                x: 0
                y: 20
                width: 50
                height: 30
                color: "#ffffff"
                text: damierQML.bestScoreQML
                bottomPadding: 5
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                font.family: "Verdana"
                font.bold: true
            }
        }

        Text {
            id: introText
            y: 80
            width: 150
            height: 40
            color: "#776e65"
            text: qsTr("Join the numbers and get to the <b>2048 tile!</b>")
            textFormat: Text.RichText
            anchors.left: parent.left
            anchors.leftMargin: 20
            font.family: "Verdana"
            wrapMode: Text.WordWrap
            font.pixelSize: 12
        }

        Rectangle {
            id: newGameRectangle
            x: 195
            y: 85
            width: 100
            height: 35
            color: "#8f7a66"
            radius: 5
            anchors.right: parent.right
            anchors.rightMargin: 25
            border.width: 0

            Text {
                id: newGameText
                color: "#f9f6f2"
                text: qsTr("New Game (press N)")
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                wrapMode: Text.WordWrap
                font.bold: true
                font.family: "Verdana"
                font.pixelSize: 12
            }
        }

        Rectangle {
            id: damier
            y: 150
            height: 280
            color: "#bbada0"
            radius: 10
            border.width: 0
            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.left: parent.left
            anchors.leftMargin: 20

            Rectangle {
                id: caseRectangle1
                x: 6
                y: 6
                width: 60
                height: 60
                color: damierQML.colorChoice(damierQML.casesQML[0])
                radius: 5
                anchors.top: parent.top
                anchors.topMargin: 8
                anchors.left: parent.left
                anchors.leftMargin: 8
                border.width: 0

                Text {
                    id: valCase1
                    text: damierQML.casesQML[0]
                    font.bold: true
                    font.family: "Verdana"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.fill: parent
                    font.pixelSize: 12
                }
            }

            Rectangle {
                id: caseRectangle2
                x: 10
                y: 9
                width: 60
                height: 60
                color: damierQML.colorChoice(damierQML.casesQML[1])
                radius: 5
                anchors.topMargin: 8
                anchors.leftMargin: 76
                anchors.left: parent.left
                border.width: 0
                anchors.top: parent.top

                Text {
                    id: valCase2
                    text: damierQML.casesQML[1]
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                    font.family: "Verdana"
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: caseRectangle3
                x: 18
                y: 14
                width: 60
                height: 60
                color: damierQML.colorChoice(damierQML.casesQML[2])
                radius: 5
                anchors.right: parent.right
                anchors.rightMargin: 76
                anchors.topMargin: 8
                border.width: 0
                anchors.top: parent.top

                Text {
                    id: valCase3
                    text: damierQML.casesQML[2]
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                    font.family: "Verdana"
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: caseRectangle4
                x: 15
                y: 16
                width: 60
                height: 60
                color: damierQML.colorChoice(damierQML.casesQML[3])
                radius: 5
                anchors.topMargin: 8
                anchors.right: parent.right
                border.width: 0
                anchors.rightMargin: 8
                anchors.top: parent.top

                Text {
                    id: valCase4
                    text: damierQML.casesQML[3]
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                    font.family: "Verdana"
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: caseRectangle5
                x: 10
                y: 10
                width: 60
                height: 60
                color: damierQML.colorChoice(damierQML.casesQML[4])
                radius: 5
                anchors.topMargin: 76
                anchors.leftMargin: 8
                anchors.left: parent.left
                border.width: 0
                anchors.top: parent.top

                Text {
                    id: valCase5
                    text: damierQML.casesQML[4]
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                    font.family: "Verdana"
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: caseRectangle6
                x: 14
                width: 60
                height: 60
                color: damierQML.colorChoice(damierQML.casesQML[5])
                radius: 5
                anchors.top: parent.top
                anchors.topMargin: 76
                anchors.leftMargin: 76
                anchors.left: parent.left
                border.width: 0

                Text {
                    id: valCase6
                    text: damierQML.casesQML[5]
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                    font.family: "Verdana"
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: caseRectangle7
                x: 22
                y: 18
                width: 60
                height: 60
                color: damierQML.colorChoice(damierQML.casesQML[6])
                radius: 5
                anchors.topMargin: 76
                anchors.right: parent.right
                border.width: 0
                anchors.rightMargin: 76
                anchors.top: parent.top

                Text {
                    id: valCase7
                    text: damierQML.casesQML[6]
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                    font.family: "Verdana"
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: caseRectangle8
                x: 19
                y: 20
                width: 60
                height: 60
                color: damierQML.colorChoice(damierQML.casesQML[7])
                radius: 5
                anchors.topMargin: 76
                anchors.right: parent.right
                border.width: 0
                anchors.rightMargin: 8
                anchors.top: parent.top

                Text {
                    id: valCase8
                    text: damierQML.casesQML[7]
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                    font.family: "Verdana"
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: caseRectangle9
                x: 1
                y: 1
                width: 60
                height: 60
                color: damierQML.colorChoice(damierQML.casesQML[8])
                radius: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 76
                anchors.leftMargin: 8
                anchors.left: parent.left
                border.width: 0

                Text {
                    id: valCase9
                    text: damierQML.casesQML[8]
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                    font.family: "Verdana"
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: caseRectangle10
                x: 5
                y: 4
                width: 60
                height: 60
                color: damierQML.colorChoice(damierQML.casesQML[9])
                radius: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 76
                anchors.leftMargin: 76
                anchors.left: parent.left
                border.width: 0

                Text {
                    id: valCase10
                    text: damierQML.casesQML[9]
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                    font.family: "Verdana"
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: caseRectangle11
                x: 13
                y: 9
                width: 60
                height: 60
                color: damierQML.colorChoice(damierQML.casesQML[10])
                radius: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 76
                anchors.right: parent.right
                border.width: 0
                anchors.rightMargin: 76

                Text {
                    id: valCase11
                    text: damierQML.casesQML[10]
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                    font.family: "Verdana"
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: caseRectangle12
                x: 10
                y: 11
                width: 60
                height: 60
                color: damierQML.colorChoice(damierQML.casesQML[11])
                radius: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 76
                anchors.right: parent.right
                border.width: 0
                anchors.rightMargin: 8

                Text {
                    id: valCase12
                    text: damierQML.casesQML[11]
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                    font.family: "Verdana"
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: caseRectangle13
                x: 5
                y: 5
                width: 60
                height: 60
                color: damierQML.colorChoice(damierQML.casesQML[12])
                radius: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 8
                anchors.leftMargin: 8
                anchors.left: parent.left
                border.width: 0

                Text {
                    id: valCase13
                    text: damierQML.casesQML[12]
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                    font.family: "Verdana"
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: caseRectangle14
                x: 9
                y: 8
                width: 60
                height: 60
                color: damierQML.colorChoice(damierQML.casesQML[13])
                radius: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 8
                anchors.leftMargin: 76
                anchors.left: parent.left
                border.width: 0

                Text {
                    id: valCase14
                    text: damierQML.casesQML[13]
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                    font.family: "Verdana"
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: caseRectangle15
                x: 17
                y: 13
                width: 60
                height: 60
                color: damierQML.colorChoice(damierQML.casesQML[14])
                radius: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 8
                anchors.right: parent.right
                border.width: 0
                anchors.rightMargin: 76

                Text {
                    id: valCase15
                    text: damierQML.casesQML[14]
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                    font.family: "Verdana"
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: caseRectangle16
                x: 14
                y: 15
                width: 60
                height: 60
                color: damierQML.colorChoice(damierQML.casesQML[15])
                radius: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 8
                anchors.right: parent.right
                border.width: 0
                anchors.rightMargin: 8

                Text {
                    id: valCase16
                    text: damierQML.casesQML[15]
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                    font.family: "Verdana"
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: gameOverRectangle
                color: "#f0e9e0"
                radius: 10
                opacity: (damierQML.gameOverQML) ? 0.7 : 0
                anchors.fill: parent

                Rectangle {
                    id: gameOverBouton
                    x: 139
                    y: 158
                    width: 100
                    height: 40
                    color: "#8f7a66"
                    radius: 10
                    border.width: 0
                    anchors.verticalCenterOffset: 20
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    z: 1

                    Text {
                        id: gameOverBoutonTexte
                        color: "#ffffff"
                        text: qsTr("New Game")
                        font.bold: true
                        font.family: "Verdana"
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        anchors.fill: parent
                        font.pixelSize: 13
                    }
                }

                Text {
                    id: gameOverText
                    text: qsTr("Game Over!")
                    bottomPadding: 50
                    font.bold: true
                    font.family: "Verdana"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    anchors.fill: parent
                    font.pixelSize: 25
                }

            }
        }

        Text {
            id: reglesDuJeu
            y: 489
            color: "#776e65"
            text: "<b>How to play:</b> Use your <b>arrow keys</b> to move the tiles. When two tiles with the same number touch, they <b>merge into one! </b>"
            elide: Text.ElideNone
            horizontalAlignment: Text.AlignJustify
            fontSizeMode: Text.FixedSize
            font.family: "Verdana"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 60
            wrapMode: Text.WordWrap
            textFormat: Text.RichText
            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.left: parent.left
            anchors.leftMargin: 20
            font.pixelSize: 12
        }

        Rectangle {
            id: ligneFin
            y: 514
            height: 1
            color: "#bbada0"
            border.width: 0
            anchors.right: parent.right
            anchors.rightMargin: 20
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 55
        }
    }
}
