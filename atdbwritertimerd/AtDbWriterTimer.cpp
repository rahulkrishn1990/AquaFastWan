#include "AtDbWriterTimer.h"

AtDbWriterTimer::AtDbWriterTimer(QObject* parent)
: QThread(parent)
{

}

void AtDbWriterTimer::fire(QString inType, int inTime)
{
	_stop = false;
	_type = inType;
	_time = inTime;
	QThread::start(QThread::NormalPriority);
}

void AtDbWriterTimer::run()
{
	qDebug() << "AtDbWriterTimer::run Started for Type: " << _type << " with Intervel: " << _time << " minutes";
	while (_stop == false)
	{
		StartProcess();
		QThread::sleep(_time * 60);
	}
}

void AtDbWriterTimer::Stopper()
{
	qDebug() << "AtDbWriterTimer::Stopper Called";
	_stop = true;
}

void AtDbWriterTimer::StartProcess()
{
	qDebug() << "AtDbWriterTimer::StartProcess Started";
	QProcess process;
	process.start(_type);
	process.waitForFinished(-1);
}
