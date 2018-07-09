

#ifndef AQUATRACER_SENSORS_SENSORLISTENER_HPP
#define AQUATRACER_SENSORS_SENSORLISTENER_HPP

#include "AquaSensorsApi/aquasensorsdefinitions.hpp"

namespace aquatracer{
namespace sensors{

class SensorListener
{
public:
    SensorListener(){}

    ~SensorListener(){}

    virtual void onNewPhMsg(const aquasensors::definitions::PhSensorMessage & msg) = 0;
};

} //sensors
} //aquatracer

#endif  //AQUATRACER_SENSORS_SENSORLISTENER_HPP
