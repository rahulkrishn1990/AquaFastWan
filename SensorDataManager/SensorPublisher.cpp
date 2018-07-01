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
{
}

void SensorPublisher::initializeTransmitter(SensorMessageTransmitter * pSensorMsgTrans)
{
    if(pSensorMsgTrans)
    {
        m_sensorMsgTransmitter = pSensorMsgTrans;
    }
}

void SensorPublisher::shutdown()
{
    m_shutDown = true;
}

void SensorPublisher::start()
{
    m_shutDown = false;
    QThread::start(QThread::NormalPriority);
}


void SensorPublisher::run()
{
    if(m_sensorMsgTransmitter)
    {
 
        while(!m_shutDown)
        {
            m_sensorMsgTransmitter->transmitPhMsg();
            // Sleep 1000ms -> 1sec
            QThread::sleep(1000);
        }
    }
}

} //sensors
} //aquatracer
