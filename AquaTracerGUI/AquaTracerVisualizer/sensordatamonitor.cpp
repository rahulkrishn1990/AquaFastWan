#include "sensordatamonitor.h"
#include <QTextStream>

namespace aquasensors{
namespace visualizer{

SensorDataMonitor::SensorDataMonitor(QObject *parent)
    :QObject(parent)
{
    m_sensorThread.start();
    m_sensorThread.addlistener(this);
}

SensorDataMonitor::~SensorDataMonitor()
{
    m_sensorThread.removelistener(this);
    m_sensorThread.shutdown();
}

void SensorDataMonitor::onNewPhMsg(const aquatracer::aquasensors::definitions::PhSensorMessage & phMsg)
{
    emit setCandidateInfoText(QString());

    QString info;
    QTextStream infoStream( &info);

    QString phVal;
    phVal.setNum(phMsg.m_PhValue);

    QString timeStamp;
    timeStamp.setNum(phMsg.m_timeStamp);

    infoStream << QString( "PhValue:  %1 ").arg(phVal);
    infoStream << QString( " at timeStamp: %1").arg(timeStamp);
    infoStream << QString( "s");
    infoStream << endl;

    emit appendCandidateInfoText(info);
}


}
}

