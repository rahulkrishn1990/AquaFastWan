
#ifndef AQUATRACER_SENSORS_SENSORMESSAGETRANSMITTER_HPP
#define AQUATRACER_SENSORS_SENSORMESSAGETRANSMITTER_HPP

#include <iostream>
#include <QThread>
#include <QDebug>
#include <QMutexLocker>
#include "AquaSensorsApi/sensormessageInterface.hpp"
#include "AquaSensorsApi/aquasensorsdefinitions.hpp"
#include "ISensorListener.hpp"

namespace aquatracer{
namespace sensors{

class SensorPublisher;

class SensorMessageTransmitter
{
public:
    SensorMessageTransmitter();
    ~SensorMessageTransmitter();

    void receive(const aquasensors::definitions::PhSensorMessage & phMsg);
    void addlistener(SensorListener * pSensorListener);
    void removelistener(SensorListener * pSensorListener);

    aquasensors::definitions::PhSensorMessage getphSensorMsg() const;

private:
    SensorPublisher * m_SensorPublisher;
    aquasensors::definitions::PhSensorMessage m_phSensorMsg;
    QMutex m_mutex;

};

} //sensors
} //aquatracer

#endif //AQUATRACER_SENSORS_SENSORMESSAGETRANSMITTER_HPP
