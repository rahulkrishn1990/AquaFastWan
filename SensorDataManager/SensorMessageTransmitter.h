
#ifndef AQUATRACER_SENSORS_SENSORMESSAGETRANSMITTER_HPP
#define AQUATRACER_SENSORS_SENSORMESSAGETRANSMITTER_HPP

#include <iostream>
#include <QThread>
#include <QDebug>
#include "AquaSensorsApi/sensormessageInterface.hpp"

namespace aquatracer{
namespace sensors{

class SensorPublisher;

class SensorMessageTransmitter
{
public:
    SensorMessageTransmitter();
    ~SensorMessageTransmitter();

    void receive(const aquasensors::definitions::PhSensorMessage & phMsg);
    void transmitPhMsg(){
        qDebug() << "Message Transmitted";
    }

private:
    SensorPublisher * m_SensorPublisher;
};

} //sensors
} //aquatracer

#endif //AQUATRACER_SENSORS_SENSORMESSAGETRANSMITTER_HPP
