#ifndef PLAYER2_H
#define PLAYER2_H

#include <QObject>
#include <QQmlContext>
#include <QGst/Pipeline>
#include <QGst/Quick/VideoSurface>

#include <QThread>
#include <QWaitCondition>
#include <QMutex>

class Player : public QThread
{
    Q_OBJECT
private:
    QQmlContext* ctx;
    QGst::PipelinePtr _pipeline;
    QGst::Quick::VideoSurface *_surface;
    QGst::ElementPtr videoSink;

    QWaitCondition  wCond;
    QMutex          mutex;

public:
    explicit Player(QQmlContext* _ctx,QObject *parent = 0);
    ~Player();    
signals:

public slots:

    void play();
    void stop();

    // QThread interface
protected:
    void run();
};

#endif // PLAYER2_H
