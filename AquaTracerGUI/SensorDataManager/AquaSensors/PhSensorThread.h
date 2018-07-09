

#ifndef AQUATRACER_AQUASENSORS_PHSENSORTHREAD_HPP
#define AQUATRACER_AQUASENSORS_PHSENSORTHREAD_HPP

#include <iostream>
#include <QThread>
#include <QElapsedTimer>
#include <QMutexLocker>

#include "../AquaSensorsApi/sensormessageInterface.hpp"
#include "../AquaSensorsApi/aquasensorsdefinitions.hpp"

namespace aquatracer{
namespace aquasensors{

class PhSensorThread /*: public QThread*/
{

//Q_OBJECT

public:
    PhSensorThread(/*QObject * parent = 0*/);

    void start();

    void registerPhSensorClient(api::IBroadcastPhSensorMessage *broadcastphclient);

    void shutdown();

    void dispatch();
private:

    bool m_shutDown;

    time_t m_lastEpochTime;

    QMutex m_mutex;

    QElapsedTimer m_elapsedTimer;

    api::IBroadcastPhSensorMessage * m_BroadcastPhMessage;
};

} //sensors
} //aquatracer

#endif  //AQUATRACER_AQUASENSORS_PHSENSORTHREAD_HPP
