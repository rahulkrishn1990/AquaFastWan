#include "AtPhClient.h"

void AtPhClient::PhReader()
{
	qDebug() << "AtDbWriterTimer::PhReader Started";
	QProcess process;
	process.start("atdbwriterclient", QStringList() << "Ph" << QString::number(qrand() % 15));
	process.waitForFinished(-1);
}
