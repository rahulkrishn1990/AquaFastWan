
#ifndef AQUATRACER_AQUASENSORS_DEFINITIONS_HPP
#define AQUATRACER_AQUASENSORS_DEFINITIONS_HPP

#include <iostream>

namespace aquatracer{
namespace aquasensors{
namespace definitions{

typedef unsigned long TimeStamp;

struct PhSensorMessage
{
    int m_PhValue;
    TimeStamp m_timeStamp;
};

} //definitions
} //aquasensors
} //aquatracer

#endif //AQUATRACER_SENSORS_DEFINITIONS_HPP
