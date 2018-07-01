
#include "PhSensorThread.h"

namespace aquatracer{
namespace aquasensors{

PhSensorThread::PhSensorThread()
    : m_shutDown( false )
    , m_BroadcastPhMessage( nullptr )
{
    m_elapsedTimer.start();
}

void PhSensorThread::shutdown()
{
    m_shutDown = true;
}

void PhSensorThread::registerPhSensorClient(api::IBroadcastPhSensorMessage * broadcastphclient)
{
    m_BroadcastPhMessage = broadcastphclient;
}

const unsigned long millisecondsToSleep = 5;

void PhSensorThread::dispatch()
{
    while(!m_shutDown)
    {
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
