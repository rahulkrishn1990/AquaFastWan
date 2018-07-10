
#ifndef AQUATRACER_AQUASENSORS_DEFINITIONS_HPP
#define AQUATRACER_AQUASENSORS_DEFINITIONS_HPP

#include <iostream>

typedef unsigned long TimeStamp;

namespace aquatracer{
namespace aquasensors{
namespace definitions{

struct PhSensorMessage
{
    int m_PhValue;
    TimeStamp m_timeStamp;
};

} //definitions
} //aquasensors
} //aquatracer

#endif //AQUATRACER_SENSORS_DEFINITIONS_HPP
