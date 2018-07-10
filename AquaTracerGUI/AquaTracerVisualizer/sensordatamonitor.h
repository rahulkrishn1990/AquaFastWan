#ifndef SENSORDATAMONITOR_H
#define SENSORDATAMONITOR_H

#include <QObject>

#include "AquaSensorsApi/aquasensorsdefinitions.hpp"
#include "../SensorDataManager/SensorThread.h"

namespace aquasensors{
namespace visualizer{


class SensorDataMonitor : public QObject, private aquatracer::sensors::SensorListener
{
    Q_OBJECT
public:
    SensorDataMonitor(QObject *parent = 0);
    virtual ~SensorDataMonitor();

signals:
    void setCandidateInfoText(const QString &);
    void appendCandidateInfoText(const QString &);

private:
    virtual void onNewPhMsg(const aquatracer::aquasensors::definitions::PhSensorMessage & phMsg);

    aquatracer::sensors::SensorThread m_sensorThread;
};

}
}
#endif // SENSORDATAMONITOR_H
