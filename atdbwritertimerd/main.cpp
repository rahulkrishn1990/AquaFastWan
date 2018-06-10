#include <iostream>
using namespace std;

#include <QDebug>
#include <QString>
#include <QCoreApplication>

#include "AtDbWriterTimer.h"

int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);
	if (argc < 2)
	{
		qDebug() << "Usage: " << argv[0] << "<Type>:<Intervel> <Type>:<Intervel> ...";
		qDebug() << "Type: Ph, Salinity";
		qDebug() << "Intervel: In minutes";
		return -1;
	}

	AtDbWriterTimer* qtDbWriterTimer;
	for (int i=1;i<argc;i++)
	{
		QString type = QString::fromStdString(argv[i]).split(":").at(0);
		int interval = QString::fromStdString(argv[i]).split(":").at(1).toInt();
		if (type.isEmpty() == false && interval > 0)
		{
			if (type == "Ph")
			{
				qDebug() << "Starting atphclient with Interval: " << interval;
				qtDbWriterTimer = new AtDbWriterTimer();
				qtDbWriterTimer->fire("atphclient", interval);
			}
			if (type == "Salinity")
			{
				qDebug() << "Starting atsalinityclient with Interval: " << interval;
				qtDbWriterTimer = new AtDbWriterTimer();
				qtDbWriterTimer->fire("atsalinityclient", interval);
			}
		}
	}

	return a.exec();
}
