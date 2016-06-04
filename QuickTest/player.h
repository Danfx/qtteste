#ifndef PLAYER2_H
#define PLAYER2_H

#include <QObject>
#include <QQmlContext>
#include <QThread>
#include <QWaitCondition>
#include <QMutex>

#include <Qt5GStreamer/QGst/Pipeline>
#include <Qt5GStreamer/QGst/Quick/VideoSurface>

//#include <QGst/Pipeline>
//#include <QGst/Quick/VideoSurface>


class Player : public QObject
{
    Q_OBJECT
private:
    QQmlContext* ctx;
    QGst::PipelinePtr _pipeline;
    QGst::Quick::VideoSurface *_surface;
    QGst::ElementPtr videoSink;

public:
    explicit Player(QQmlContext* _ctx,QObject *parent = 0);
    ~Player();    
signals:

public slots:

    void play();
    void stop();

};

#endif // PLAYER2_H
