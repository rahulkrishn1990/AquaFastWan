#ifndef BROADCASTPHSENSORMESSAGE_HPP
#define BROADCASTPHSENSORMESSAGE_HPP

#include <memory>

#include "AquaSensorsApi/sensormessageInterface.hpp"
#include "SensorMessageTransmitter.h"

namespace aquatracer {
namespace sensors {

class BroadcastPhSensorMessage : public aquasensors::api::IBroadcastPhSensorMessage
{
public:
   BroadcastPhSensorMessage( const std::shared_ptr<aquatracer::sensors::SensorMessageTransmitter> & m_sensorMessageTransmitter );
   virtual ~BroadcastPhSensorMessage();

   virtual void onNewPhSensorMessage( const aquasensors::definitions::PhSensorMessage & message_PhSensor);

private:
   
   std::shared_ptr<aquatracer::sensors::SensorMessageTransmitter> m_sensorMessageTransmitter;
};

} // namespace sensors
} // namespace aquatracer

#endif // BROADCASTPHSENSORMESSAGE_HPP

