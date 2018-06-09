#ifndef ATDBWRITERCLIENT_ATDBWRITER_H_
#define ATDBWRITERCLIENT_ATDBWRITER_H_

#include <iostream>
using namespace std;

#include <sqlite3.h>

#include <QDir>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QStringList>

#include "Globel.h"

class AtDbWriter
{
public:
	AtDbWriter();
	virtual ~AtDbWriter();
	bool Insert(QString, QString);

private:
	bool InitializeDbFile();
	QString Schema(QString, QString);

private:
	sqlite3* _sqlite3;
	QString  _dbFile;
};

#endif /* ATDBWRITERCLIENT_ATDBWRITER_H_ */
