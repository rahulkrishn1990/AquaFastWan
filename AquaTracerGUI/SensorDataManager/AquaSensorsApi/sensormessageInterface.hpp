
#ifndef AQUATRACER_AQUASENSORS_IBROADCASTPHSENSORMESSAGE_HPP
#define AQUATRACER_AQUASENSORS_IBROADCASTPHSENSORMESSAGE_HPP

#include "aquasensorsdefinitions.hpp"
#include "../SensorMessageTransmitter.h"

namespace aquatracer{
namespace aquasensors{
namespace api{

/** indicate event reception using broadcast semantic */
class IBroadcastPhSensorMessage
{
   public:

//      IBroadcastPhSensorMessage(const std::shared_ptr<aquatracer::sensors::SensorMessageTransmitter>& sensorMessageTransmitter){}

      /** */
      virtual ~IBroadcastPhSensorMessage(){}

      /**
       * @brief receive a broadcast message
       * @param[in] callStatus
       * - SUCCESS if message was normally received
       * - CONNECTION_FAILED if server is down. All subscriptions are lost.
       *
       * @param[in] message_BV_Linie_01
       */
      virtual void onNewPhSensorMessage( const definitions::PhSensorMessage & message_PhSensor) = 0;
};

} //api
} //aquasensors
} //aquatracer

#endif //AQUATRACER_AQUASENSORS_IBROADCASTPHSENSORMESSAGE_HPP
