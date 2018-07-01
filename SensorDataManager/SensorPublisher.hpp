

#ifndef AQUATRACER_SENSORS_SENSORPUBLISHER_HPP
#define AQUATRACER_SENSORS_SENSORPUBLISHER_HPP

#include <iostream>
#include <QThread>

namespace aquatracer{
namespace sensors{

class SensorMessageTransmitter;

class SensorPublisher : public QThread
{
    Q_OBJECT
public:
    SensorPublisher(QObject * parent = 0);

    void initializeTransmitter(SensorMessageTransmitter * pSensorMsgTrans);
    void start();
    void shutdown();
    void run();

private:
   bool m_shutDown;

   SensorMessageTransmitter * m_sensorMsgTransmitter;
};

} //sensors
} //aquatracer

#endif  //AQUATRACER_SENSORS_SENSORTHREAD_HPP
