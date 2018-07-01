

#ifndef AQUATRACER_SENSORS_SENSORTHREAD_HPP
#define AQUATRACER_SENSORS_SENSORTHREAD_HPP

#include <iostream>
#include <QThread>

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

    bool m_shutDown;
private:
    aquasensors::PhSensorThread m_phSensThread;

};

} //sensors
} //aquatracer

#endif  //AQUATRACER_SENSORS_SENSORTHREAD_HPP
