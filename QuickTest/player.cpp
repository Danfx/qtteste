#include "player.h"

#include <Qt5GStreamer/QGst/ElementFactory>
#include <Qt5GStreamer/QGst/Pipeline>
#include <Qt5GStreamer/QGst/Message>
#include <Qt5GStreamer/QGst/Quick/VideoSurface>

//#include <QGst/ElementFactory>
//#include <QGst/Pipeline>
//#include <QGst/Message>
//#include <QGst/Quick/VideoSurface>


#define THREAD_SCOPE


Player::Player(QQmlContext *_ctx, QObject *parent) :
    QThread(parent),
    ctx(_ctx),    
    _surface(NULL)
{

}

Player::~Player()
{
    this->stop();
}

void Player::stop(){
    wCond.wakeAll();
    while( !isFinished() )
        msleep(100);
}

void Player::play()
{
    qDebug("playing");    

    if( isRunning() ){
        this->stop();
        delete _surface;
    }

#ifndef THREAD_SCOPE
    _surface = new QGst::Quick::VideoSurface();
    ctx->setContextProperty(QLatin1String("videoSurface1"), _surface);
    videoSink = _surface->videoSink();
#endif    

    this->start();
}

void Player::run()
{
    qDebug() << "Running" << this->currentThreadId();

    /* Create video pipeline */
    QGst::PipelinePtr _pipeline;
    _pipeline = QGst::ElementFactory::make("playbin").dynamicCast<QGst::Pipeline>();

#ifdef THREAD_SCOPE
    QGst::Quick::VideoSurface* _surface = new QGst::Quick::VideoSurface();
    ctx->setContextProperty(QLatin1String("videoSurface1"), _surface);
    QGst::ElementPtr videoSink = _surface->videoSink();
#endif

    if (_pipeline) {
        QString uri = "rtsp://184.72.239.149/vod/mp4:BigBuckBunny_115k.mov";
        videoSink->setProperty("async",false);
        videoSink->setProperty("sync",false);
        _pipeline->setProperty("uri", uri);
        _pipeline->setProperty("video-sink",videoSink);
        _pipeline->setProperty("force-aspect-ratio",false);
        _pipeline->setState(QGst::StatePlaying);
    } else {
        qCritical() << "Failed to create the pipeline";
    }

    qDebug() << "Waiting..." << this->currentThreadId();

    /* Create wait condition */
    wCond.wait(&mutex);

    _pipeline->setState(QGst::StateNull);    

    qDebug() << "Finished: " << this->currentThreadId();
}
