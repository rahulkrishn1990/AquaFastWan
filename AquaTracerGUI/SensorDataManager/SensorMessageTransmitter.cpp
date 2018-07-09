
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
    QMutexLocker lock(&m_mutex);
    m_phSensorMsg = phMsg;
    qDebug() << "PhVal is : " << phMsg.m_PhValue;
    qDebug() << "TimeStamp : " << phMsg.m_timeStamp;
}

aquasensors::definitions::PhSensorMessage SensorMessageTransmitter::getphSensorMsg() const
{
//    QMutexLocker lock(&m_mutex);
    return m_phSensorMsg;
}

void SensorMessageTransmitter::addlistener(SensorListener * pSensorListener)
{
    QMutexLocker lock(&m_mutex);
    m_SensorPublisher->addlistener(pSensorListener);
}

void SensorMessageTransmitter::removelistener(SensorListener * pSensorListener)
{
    QMutexLocker lock(&m_mutex);
    m_SensorPublisher->removelistener(pSensorListener);
}



//const int timeIntervalInMs = 100;
//int timeStamp = m_elapsedTimer.elapsed();
//if( m_lastEpochTime == 0 || (timeStamp - m_lastEpochTime) >= timeIntervalInMs) {

//m_lastEpochTime = timeStamp;
//}


} //sensors
} //aquatracer
