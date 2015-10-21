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
        Qt5GLib-2.0 \
        gstreamer-1.0 \
        glib-2.0
}

INCLUDEPATH += \
    /opt/poky/1.7.2/sysroots/armv7at2hf-vfp-neon-poky-linux-gnueabi/usr/include/Qt5GStreamer \
    /opt/poky/1.7.2/sysroots/armv7at2hf-vfp-neon-poky-linux-gnueabi/usr/include/gstreamer-1.0 \
    /opt/poky/1.7.2/sysroots/armv7at2hf-vfp-neon-poky-linux-gnueabi/usr/include/glib-2.0 \
    /opt/poky/1.7.2/sysroots/armv7at2hf-vfp-neon-poky-linux-gnueabi/usr/lib/glib-2.0/include
