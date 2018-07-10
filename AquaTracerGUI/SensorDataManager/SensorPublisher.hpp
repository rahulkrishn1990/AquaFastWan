

#ifndef AQUATRACER_SENSORS_SENSORPUBLISHER_HPP
#define AQUATRACER_SENSORS_SENSORPUBLISHER_HPP

#include <iostream>
#include <QThread>
#include "QMutexLocker"

#include "ISensorListener.hpp"
#include <list>

namespace aquatracer{
namespace sensors{

class SensorMessageTransmitter;

class SensorPublisher : public QThread
{
    Q_OBJECT
public:
    SensorPublisher(QObject * parent = 0);

    void addlistener(SensorListener* pSensorListener);
    void initializeTransmitter(SensorMessageTransmitter * pSensorMsgTrans);
    void start();
    void shutdown();
    void run();

    void removelistener(SensorListener * pSensorListener);
private:

   void notifylisteners(aquasensors::definitions::PhSensorMessage phSensorMessage);


   bool m_shutDown;

   SensorMessageTransmitter * m_sensorMsgTransmitter;

   std::list<SensorListener*> m_listeners;
   QMutex m_mutex;

   TimeStamp m_lastEpochTime;
};

} //sensors
} //aquatracer

#endif  //AQUATRACER_SENSORS_SENSORTHREAD_HPP
