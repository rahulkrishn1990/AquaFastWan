
#include "SensorMessageTransmitter.h"
#include "broadcastPhSensorMessage.hpp"
#include "SensorPublisher.hpp"

namespace aquatracer{
namespace sensors{

SensorMessageTransmitter::SensorMessageTransmitter()
    : m_SensorPublisher(new SensorPublisher())
{
    if(m_SensorPublisher)
    {
        m_SensorPublisher->initializeTransmitter(this);
        m_SensorPublisher->start();
    }
}

SensorMessageTransmitter::~SensorMessageTransmitter()
{
    m_SensorPublisher->shutdown();
}

void SensorMessageTransmitter::receive(const aquasensors::definitions::PhSensorMessage & phMsg)
{
    qDebug() << "PhVal is : " << phMsg.m_PhValue;
    qDebug() << "TimeStamp : " << phMsg.m_timeStamp;
}

//const int timeIntervalInMs = 100;
//int timeStamp = m_elapsedTimer.elapsed();
//if( m_lastEpochTime == 0 || (timeStamp - m_lastEpochTime) >= timeIntervalInMs) {

//m_lastEpochTime = timeStamp;
//}


} //sensors
} //aquatracer
