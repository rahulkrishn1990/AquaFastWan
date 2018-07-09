#include <memory>
#include "SensorThread.h"
#include "SensorMessageTransmitter.h"
#include "broadcastPhSensorMessage.hpp"

namespace aquatracer{
namespace sensors{

SensorThread::SensorThread(QObject *parent)
    : QThread(parent)
    , m_shutDown( false )
    , m_SensorMsgTransmitter( nullptr )
{
    m_SensorMsgTransmitter = std::make_shared<SensorMessageTransmitter>();
}

void SensorThread::shutdown()
{
    QMutexLocker lock(&m_mutex);
    m_shutDown = true;
    m_phSensThread.shutdown();
}

void SensorThread::start()
{
    QMutexLocker lock(&m_mutex);
    m_shutDown = false;

    QThread::start(QThread::NormalPriority);
}

void SensorThread::run()
{
    if(m_SensorMsgTransmitter)
    {
        BroadcastPhSensorMessage broadCastPhMsg(m_SensorMsgTransmitter);
        m_phSensThread.registerPhSensorClient(&broadCastPhMsg);

        // some client to be registered that is reading ph Messages
        while(!m_shutDown)
        {
            QMutexLocker lock(&m_mutex);
            m_phSensThread.dispatch();
            // Sleep 1000ms -> 1sec
            QThread::sleep(1000);
        }
    }
}

void SensorThread::addlistener(SensorListener * pSensorListener)
{
    QMutexLocker lock(&m_mutex);
    m_SensorMsgTransmitter->addlistener(pSensorListener);
}

void SensorThread::removelistener(SensorListener * pSensorListener)
{
    QMutexLocker lock(&m_mutex);
    m_SensorMsgTransmitter->removelistener(pSensorListener);
}



} //sensors
} //aquatracer
