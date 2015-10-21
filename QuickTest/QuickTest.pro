TEMPLATE = app

QT += qml quick declarative

SOURCES += main.cpp \
    player.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    player.h

unix {
    CONFIG += link_pkgconfig

    PKGCONFIG += \
        Qt5GStreamer-1.0 \
        Qt5GStreamerUtils-1.0 \
        Qt5GStreamerUi-1.0 \
        Qt5GStreamerQuick-1.0 \
        Qt5GLib-2.0
}

