
#ifndef QDEVICECHANGEEVENT_H
#define QDEVICECHANGEEVENT_H

#include <QtCore/QEvent>
#include <QtCore/QString>
#include "qdevicewatcher_global.h"

class Q_DLL_EXPORT QDeviceChangeEvent : public QEvent
{
    Q_ENUMS(Action)
public:
    enum Action { Add, Remove, Change};
    //static const Type EventType; //VC link error

    explicit QDeviceChangeEvent(Action action, const QString& device);

    Action action() const {return m_action;}
    QString device() const {return m_device;}
    static Type registeredType()
    {
        static Type EventType = static_cast<Type>(registerEventType());
        return EventType;
    }

private:
    Action m_action;
    QString m_device;
};

#endif // QDEVICECHANGEEVENT_H
