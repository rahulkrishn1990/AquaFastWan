#include <memory>
#include "SensorThread.h"
#include "SensorMessageTransmitter.h"
#include "broadcastPhSensorMessage.hpp"

namespace aquatracer{
namespace sensors{

SensorThread::SensorThread(QObject *parent)
    : QThread(parent)
    , m_shutDown( false )
{
}

void SensorThread::shutdown()
{
    m_shutDown = true;
    m_phSensThread.shutdown();
}

void SensorThread::start()
{
    m_shutDown = false;
    QThread::start(QThread::NormalPriority);
}

void SensorThread::run()
{
    std::shared_ptr<SensorMessageTransmitter> sensorMsgTransmitter = std::make_shared<SensorMessageTransmitter>();

    if(sensorMsgTransmitter)
    {
        // some client to be registered that is reading ph Messages
        BroadcastPhSensorMessage broadCastPhMsg(sensorMsgTransmitter);

        m_phSensThread.registerPhSensorClient(&broadCastPhMsg);

        while(!m_shutDown)
        {
            m_phSensThread.dispatch();
            // Sleep 1000ms -> 1sec
           QThread::sleep(1000);
        }
    }
}

} //sensors
} //aquatracer
