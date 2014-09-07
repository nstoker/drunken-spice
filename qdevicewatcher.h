#ifndef QDEVICEWATCHER_H
#define QDEVICEWATCHER_H

#include <QObject>
#include <QtCore/QObject>
#include "qdevicewatcher_global.h"

class QDeviceWatcherPrivate;

class Q_DLL_EXPORT QDeviceWatcher : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(QDeviceWatcher)
public:
    explicit QDeviceWatcher(QObject *parent = 0);
    ~QDeviceWatcher();

    bool start();
    bool stop();
    bool isRunning() const;

    void appendEventReceiver(QObject* receiver);

signals:
    void deviceAdded(const QString& dev);
    void deviceChanged(const QString& dev); //when umounting the device
    void deviceRemoved(const QString& dev);

protected:
    bool running;
    QDeviceWatcherPrivate *d_ptr;
};

#endif // QDEVICEWATCHER_H
