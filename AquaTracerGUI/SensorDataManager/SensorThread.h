

#ifndef AQUATRACER_SENSORS_SENSORTHREAD_HPP
#define AQUATRACER_SENSORS_SENSORTHREAD_HPP

#include <iostream>
#include <memory>

#include <QThread>
#include <QMutexLocker>

#include "ISensorListener.hpp"
#include "AquaSensors/PhSensorThread.h"

namespace aquatracer{
namespace sensors{

class SensorThread : public QThread
{
    Q_OBJECT
public:
    SensorThread(QObject * parent = 0);

    void start();
    void shutdown();
    void run();

    void addlistener(SensorListener * pSensorListener);
    void removelistener(SensorListener * pSensorListener);

private:
    bool m_shutDown;
    aquasensors::PhSensorThread m_phSensThread;
    std::shared_ptr<SensorMessageTransmitter> m_SensorMsgTransmitter;
    QMutex m_mutex;
};

} //sensors
} //aquatracer

#endif  //AQUATRACER_SENSORS_SENSORTHREAD_HPP
