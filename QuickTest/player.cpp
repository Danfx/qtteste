#include "player.h"

#include <Qt5GStreamer/QGst/ElementFactory>
#include <Qt5GStreamer/QGst/Pipeline>
#include <Qt5GStreamer/QGst/Message>
#include <Qt5GStreamer/QGst/Quick/VideoSurface>

//#include <QGst/ElementFactory>
//#include <QGst/Pipeline>
//#include <QGst/Message>
//#include <QGst/Quick/VideoSurface>


Player::Player(QQmlContext *_ctx, QObject *parent) :
    QObject(parent),
    ctx(_ctx),    
    _surface(NULL)
{

}

Player::~Player()
{
    this->stop();
}

void Player::stop(){

    qDebug() << "Stopping";

    if( _pipeline ){
        /* Stop pipeline */
        _pipeline->setState(QGst::StateNull);
        _pipeline.clear();

        /* Clean Surface */
        ctx->setContextProperty(QLatin1String("videoSurface1"), NULL);
        delete _surface;
    }
}

void Player::play()
{
    this->stop();

    qDebug() << "Playing";

    /* Creating surface */
    _surface = new QGst::Quick::VideoSurface();
    ctx->setContextProperty(QLatin1String("videoSurface1"), _surface);
    videoSink = _surface->videoSink();
    videoSink->setProperty("sync",false);

    /* Create video pipeline */
    _pipeline = QGst::ElementFactory::make("playbin").dynamicCast<QGst::Pipeline>();

    if (_pipeline) {
        QString uri = "rtsp://184.72.239.149/vod/mp4:BigBuckBunny_115k.mov";
        _pipeline->setProperty("uri", uri);
        _pipeline->setProperty("video-sink",videoSink);
        _pipeline->setState(QGst::StatePlaying);
    }

}
