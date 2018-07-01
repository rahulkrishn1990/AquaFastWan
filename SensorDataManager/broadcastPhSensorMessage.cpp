#include "broadcastPhSensorMessage.hpp"

namespace aquatracer {
namespace sensors {

BroadcastPhSensorMessage::BroadcastPhSensorMessage( const std::shared_ptr<aquatracer::sensors::SensorMessageTransmitter>& sensorMessageTransmitter )
: m_sensorMessageTransmitter( sensorMessageTransmitter )
{   
}

BroadcastPhSensorMessage::~BroadcastPhSensorMessage()
{
}

void BroadcastPhSensorMessage::onNewPhSensorMessage( const aquasensors::definitions::PhSensorMessage & message_PhSensor )
{
   // TODO add status error handling
      m_sensorMessageTransmitter->receive( message_PhSensor );
}

} // namespace sensors
} // namespace aquatracer


