#include <memory>
#include "SensorPublisher.hpp"
#include "AquaSensorsApi/sensormessageInterface.hpp"
#include "SensorMessageTransmitter.h"

namespace aquatracer{
namespace sensors{

SensorPublisher::SensorPublisher( QObject *parent)
    : QThread(parent)
    , m_sensorMsgTransmitter(nullptr)
    , m_shutDown( false )
    , m_lastEpochTime(0)
{
}

void SensorPublisher::initializeTransmitter(SensorMessageTransmitter * pSensorMsgTrans)
{
    if(pSensorMsgTrans)
    {
        QMutexLocker lock(&m_mutex);
        m_sensorMsgTransmitter = pSensorMsgTrans;
    }
}

void SensorPublisher::shutdown()
{
    QMutexLocker lock(&m_mutex);
    m_shutDown = true;
}

void SensorPublisher::start()
{
    QMutexLocker lock(&m_mutex);
    m_shutDown = false;
    QThread::start(QThread::NormalPriority);
}

void SensorPublisher::run()
{
    // use mutex guards
    if(m_sensorMsgTransmitter)
    {
        while(!m_shutDown)
        {
            aquasensors::definitions::PhSensorMessage phSensorMessage;
            {
                //get the timing based ph msg.
                QMutexLocker lock(&m_mutex);
                phSensorMessage = m_sensorMsgTransmitter->getphSensorMsg();
            }

            const int timeIntervalInMs = 100;

            if( m_lastEpochTime == 0 || (phSensorMessage.m_timeStamp - m_lastEpochTime) >= timeIntervalInMs)
            {
                notifylisteners(phSensorMessage);
                m_lastEpochTime = phSensorMessage.m_timeStamp;
            }

        }
    }
}

void SensorPublisher::addlistener(SensorListener * pSensorListener)
{
    QMutexLocker lock(&m_mutex);
    m_listeners.push_back(pSensorListener);
}

void SensorPublisher::removelistener(SensorListener * pSensorListener)
{
    QMutexLocker lock(&m_mutex);
    if(!m_listeners.empty())
    {
        m_listeners.remove(pSensorListener);
    }
}

void SensorPublisher::notifylisteners(aquasensors::definitions::PhSensorMessage phSensorMessage)
{
    for(SensorListener *pListener : m_listeners)
    {
        pListener->onNewPhMsg(phSensorMessage);
    }
}



} //sensors
} //aquatracer
