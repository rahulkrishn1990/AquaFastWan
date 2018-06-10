#ifndef ATDBWRITERCLIENT_ATDBWRITERTIMER_H_
#define ATDBWRITERCLIENT_ATDBWRITERTIMER_H_

#include <iostream>
using namespace std;

#include <QDebug>
#include <QString>
#include <QThread>
#include <QProcess>

class AtDbWriterTimer : public QThread
{
    Q_OBJECT
public:
	AtDbWriterTimer(QObject *parent = 0);
    void fire(QString, int);
    void run();
    void Stopper();

private:
    void StartProcess();

private:
    bool 	_stop;
    QString	_type;
    int		_time;
};

#endif
