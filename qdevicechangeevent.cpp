#include "qdevicechangeevent.h"

//const QEvent::Type  QDeviceChangeEvent::EventType = static_cast<QEvent::Type>(QEvent::registerEventType());
QDeviceChangeEvent::QDeviceChangeEvent(Action action, const QString &device) :
    QEvent(registeredType())
{
    m_action = action;
    m_device = device;
}

