
#include "PhSensorThread.h"

namespace aquatracer{
namespace aquasensors{

PhSensorThread::PhSensorThread()
    : m_shutDown( false )
    , m_BroadcastPhMessage( 0 )
{
    m_elapsedTimer.start();
}

void PhSensorThread::shutdown()
{
    QMutexLocker lock(&m_mutex);
    m_shutDown = true;
}

void PhSensorThread::registerPhSensorClient(api::IBroadcastPhSensorMessage * broadcastphclient)
{
    QMutexLocker lock(&m_mutex);
    m_BroadcastPhMessage = broadcastphclient;
}

const unsigned long millisecondsToSleep = 5;

void PhSensorThread::dispatch()
{
    while(!m_shutDown)
    {
//        QMutexLocker lock(&m_mutex);

        m_mutex.lock();
        int64_t timeStamp = m_elapsedTimer.elapsed();
        aquasensors::definitions::PhSensorMessage phMsg;
        phMsg.m_PhValue = std::rand() % 15;
        phMsg.m_timeStamp = timeStamp;

        if(m_BroadcastPhMessage)
        {
            m_BroadcastPhMessage->onNewPhSensorMessage(phMsg);
        }
        m_mutex.unlock();

        QThread::sleep( millisecondsToSleep );
    }
}

} //sensors
} //aquatracer
