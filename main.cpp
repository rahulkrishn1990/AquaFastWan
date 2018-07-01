
#include <iostream>
#include <QDebug>
#include <QString>
#include <QCoreApplication>

#include "SensorThread.h"

int main(int argc, char* argv[])
{
    using namespace aquatracer::sensors;
    QCoreApplication a(argc, argv);

    SensorThread sensorDataThread;


    while(!sensorDataThread.m_shutDown)
    {
        for(int i = 0; i < 10000000000; ++i)
        {
            sensorDataThread.start();
        }
        sensorDataThread.shutdown();
    }

    qDebug() << "Shut Down Called";


    return a.exec();
}
